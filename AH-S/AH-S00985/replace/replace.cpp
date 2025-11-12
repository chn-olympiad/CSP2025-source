#include <iostream>
#include <time.h>
using namespace std;

int n, q;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> q;
    for (int i = 1; i  <= q; ++i) {
        cout << rand() <<"\n";
    }

    return 0;
}
