#include "testlib.h"
#include <cmath>

using namespace std;

const double EPS = 1E-10;

int main(int argc, char * argv[])
{
    setName("compare two sequences of doubles, max absolute or relative error = %.11lf", EPS);
    registerTestlibCmd(argc, argv);

    int n = 0;
    double j, p;

    while (!ans.seekEof()) 
    {
        n++;
        j = ans.readDouble();
        p = ouf.readDouble();
        if (!doubleCompare(j, p, EPS))
        {
            quitf(_wa, "%d%s numbers differ - expected: '%.11lf', found: '%.11lf', error = '%.11lf'",
                n, englishEnding(n).c_str(), j, p, doubleDelta(j, p));
        }
    }

    if (n == 1)
        quitf(_ok, "found '%.11lf', expected '%.11lf', error '%.11lf'", p, j, doubleDelta(j, p));

    quitf(_ok, "%d numbers", n);
}
