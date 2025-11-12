#include "fstream"
#include "vector"
#include "algorithm"

using namespace std;

bool down(int a, int b) {
    if (a > b) return true;
    else return false;
}

int main() {
    ifstream inf("seat.in");
    ofstream outf("seat.out");
    int n, m;
    inf >> n >> m;
    vector<int> a(n * m);
    for (int i = 0; i < n * m; i++) {
        inf >> a.at(i);
    }
    int p = a.at(0);
    sort(a.begin(), a.end(), down);
    int i = 0;
    while (a.at(i) != p) i++;
    int c = i / n + 1;
    int r = c % 2 == 1 ? i % n + 1: n - (i % n);
    outf << c << ' ' << r;
    return 0;
}
