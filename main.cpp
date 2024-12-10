#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

// S pomočjo c++ programa izračunaj naslednjo linearno in kvadratno funkcijo:
// y1 = 0.31 * x + 19.7
// y2 = 0.31 * x^2
//
// Nariši funkciji v GNUplot in OriginLab, ter najdi točko intersekcije (točka kjer se ti dve funkciji srečata).
// Poiskusi še najti intersekcijo med linearno in kvadratno funkcijo s pomočjo c++.

using namespace std;

double calculateLinear(double x, double k, double a) {
    return k * x + a;
}

double calculateQuadratic(double x, double a, double b, double c) {
    return a * x * x + b * x + c;
}

double nextNearestPoint(vector<vector<double>> &data, double startX, double tolerance) {
    double closestVal;
    double closestX;
    double closestDelta = tolerance;
    double prevClosestDelta = tolerance;
    for (int i = 0; i < data[0].size(); i++) {
        double delta = abs(data[1][i] - data[2][i]);
        if (closestDelta > delta) {
            closestDelta = delta;
            closestX = data[0][i];
        }
        else if (abs(data[1][i] - data[2][i])) {

        }
    }

    //todo ko zazna najmanjso returna... ne do konca!

    return closestX;
}

int main() {

    double step = 0.001;
    double xStart = -100;
    double xEnd = 100;

    vector<vector<double>> data(3);

    // x    lin.   quad
    // 1    123    542
    //...

    for (double x = xStart; x <= xEnd; x += step) {
        data[0].push_back(x);
        data[1].push_back(calculateLinear(x, 0.31,19.7));
        data[2].push_back(calculateQuadratic(x, 0.31, 0, 0));
    }

    //izpis podatkov
    ofstream of("output.dat");
    of << fixed << setprecision(6);

    for (int i = 0; i < data[0].size(); i++) {
        of <<  data[0][i] << " " << data[1][i] << " " << data[2][i] << endl;
    }
    of.close();
    double tolerance = 0.01;
    double closestX =  nextNearestPoint(data, xStart, tolerance);
    cout << "Closest X: " << closestX << endl;
    return 0;
}