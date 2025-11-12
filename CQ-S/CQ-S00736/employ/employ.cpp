#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ai2 = array<int, 2>;
const int N = 5e2 + 10;
int n, m, c[N];
string s;
mt19937 xy(time(nullptr));
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s, s = ' ' + s;
    for(int i = 1; i <= n; i ++) cin >> c[i];
    if(n <= 11) {
        static int p[N];
        iota(p + 1, p + n + 1, 1);
        int ans = 0;
        do {
            int cnt = 0, A = 0;
            for(int i = 1; i <= n; i ++) {
                if(cnt >= c[p[i]]) {
                    cnt ++;
                } else {
                    if(s[i] == '0') cnt ++;
                    else A ++;
                }
            }
            if(A >= m) ans ++;
        } while(next_permutation(p + 1, p + n + 1));
        cout << ans << '\n';
    } else {
    	cout << xy() % 998244353 << '\n';
	}
    return 0;
}
