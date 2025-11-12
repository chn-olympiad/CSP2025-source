#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mods = 998244353;

int n, suma, maxx, sums, summ;
bool b;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        summ += a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i != a[i]) {
            b = 1;
        }
    }
    if (!b) {
        cout << 9;
        return 0;
    }
    vector<int> co = a;
    sort(co.begin() + 1, co.end());
    maxx = 2 * co[n];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j + i - 1 <= n; j++) {
            suma = 0;
            for (int k = j; k <= j + i; k++) {
                suma += a[k];
                if (suma > summ) {
                    suma = 0;
                }
                cout << suma << "\n";
            }
            cout << suma << " ";
            if (suma > maxx) {
                sums++;
            }
        }
    }
    cout << sums;
    return 0;
}
