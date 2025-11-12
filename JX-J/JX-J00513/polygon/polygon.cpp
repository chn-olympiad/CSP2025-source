#include "fstream"
#include "vector"

#define MOD 998244353

using namespace std;

int main() {
    ifstream inf("polygon.in");
    ofstream outf("polygon.ans");
    int n;
    inf >> n;
    vector<int> a(n);
    int m = 0;
    long long int s = 0;
    for (int i = 0; i < n; i++) {
        inf >> a.at(i);
        if (a.at(i) > m) m = a.at(i);
        s += a.at(i);
    }
    int r = 0;
    if (n >= 3) {
        if (m < 2 * s) {
            r = 1;
        }
    }
    outf << r;
    return 0;
}
