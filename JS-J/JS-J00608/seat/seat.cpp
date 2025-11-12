#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    freopen("seat.out", "w", stdout);
    freopen("seat.in", "r", stdin);

    int n, m;
    cin >> n >> m;
    int l = 1;
    int ms; cin >> ms;
    for (int i = 1; i < n * m; ++i) {
        int oscr; cin >> oscr;
        if (oscr > ms) {
            ++l;
        }
    }
    int hang = (l - 1) % n;
    int lie = ((l - hang) / m) + 1;
    if (lie % 2 == 0) {
        hang = n - hang;
    } else {
        ++hang;
    }
    cout << lie << ' ' << hang;

    return 0;
}

