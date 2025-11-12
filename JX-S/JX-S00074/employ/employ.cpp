#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 505;
int c[N], ans, p[N];
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
    int n, m;
    string s;
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    do {
        int len = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (len < c[p[i]] && s[i] == '1') ++cnt;
            else ++len;
        }
        if (cnt >= m) ++ans;
    } while (next_permutation(p, p + n));
    cout << ans;
	return 0;
}
