#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
constexpr int N = 5005;
constexpr int mod = 998244353;

int n;
int a[N];
inline int pppt(const int& num) ;
inline int pppa(const int& n1, const int& n2) { return (pppt(n1) / pppt(n1 - n2) + mod) % mod; }
inline int pppc(const int& n1, const int& n2) { return (pppa(n1, n2) / pppt(n2) + mod) % mod; }
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
	if (n == 3) {
        cout << ((a[1] + a[2] > a[3]) ? 1 : 0) << endl;
        return 0;
	}
	if (n == 4) {
        int cnt = 0;
        if (a[1] + a[2] > a[3]) ++cnt;
        if (a[1] + a[2] > a[4]) ++cnt;
        if (a[1] + a[3] > a[4]) ++cnt;
        if (a[2] + a[3] > a[4]) ++cnt;
        if (a[1] + a[2] + a[3] > a[4]) ++cnt;
        cout << cnt << endl;
        return 0;
	}
	if (n == 5) {
        int cnt = 0;
        if (a[1] + a[2] > a[3]) ++cnt;
        if (a[1] + a[2] > a[4]) ++cnt;
        if (a[1] + a[2] > a[5]) ++cnt;
        if (a[1] + a[3] > a[4]) ++cnt;
        if (a[1] + a[3] > a[5]) ++cnt;
        if (a[1] + a[4] > a[5]) ++cnt;
        if (a[2] + a[3] > a[4]) ++cnt;
        if (a[2] + a[3] > a[5]) ++cnt;
        if (a[2] + a[4] > a[5]) ++cnt;
        if (a[3] + a[4] > a[5]) ++cnt;
        if (a[1] + a[2] + a[3] > a[4]) ++cnt;
        if (a[1] + a[2] + a[3] > a[5]) ++cnt;
        if (a[1] + a[2] + a[4] > a[5]) ++cnt;
        if (a[1] + a[3] + a[4] > a[5]) ++cnt;
        if (a[2] + a[3] + a[4] > a[5]) ++cnt;
        if (a[1] + a[2] + a[3] + a[4] > a[5]) ++cnt;
        cout << cnt << endl;
        return 0;
	}
	if (n == 6) {
        int cnt = 0;
        if (a[1] + a[2] > a[3]) ++cnt;
        if (a[1] + a[2] > a[4]) ++cnt;
        if (a[1] + a[2] > a[5]) ++cnt;
        if (a[1] + a[2] > a[6]) ++cnt;
        if (a[1] + a[3] > a[4]) ++cnt;
        if (a[1] + a[3] > a[5]) ++cnt;
        if (a[1] + a[3] > a[6]) ++cnt;
        if (a[1] + a[4] > a[5]) ++cnt;
        if (a[1] + a[4] > a[6]) ++cnt;
        if (a[1] + a[5] > a[6]) ++cnt;
        if (a[2] + a[3] > a[4]) ++cnt;
        if (a[2] + a[3] > a[5]) ++cnt;
        if (a[2] + a[3] > a[6]) ++cnt;
        if (a[2] + a[4] > a[5]) ++cnt;
        if (a[2] + a[4] > a[6]) ++cnt;
        if (a[2] + a[5] > a[6]) ++cnt;
        if (a[3] + a[4] > a[5]) ++cnt;
        if (a[3] + a[4] > a[6]) ++cnt;
        if (a[4] + a[5] > a[6]) ++cnt;
        if (a[1] + a[2] + a[3] > a[4]) ++cnt;
        if (a[1] + a[2] + a[3] > a[5]) ++cnt;
        if (a[1] + a[2] + a[3] > a[6]) ++cnt;
        if (a[1] + a[2] + a[4] > a[5]) ++cnt;
        if (a[1] + a[2] + a[4] > a[6]) ++cnt;
        if (a[1] + a[2] + a[5] > a[6]) ++cnt;
        if (a[1] + a[3] + a[4] > a[5]) ++cnt;
        if (a[1] + a[3] + a[4] > a[6]) ++cnt;
        if (a[2] + a[3] + a[4] > a[5]) ++cnt;
        if (a[2] + a[3] + a[4] > a[6]) ++cnt;
        if (a[2] + a[3] + a[5] > a[6]) ++cnt;
        if (a[3] + a[4] + a[5] > a[6]) ++cnt;
        if (a[1] + a[2] + a[3] + a[4] > a[5]) ++cnt;
        cout << cnt << endl;
        return 0;
	}
	int sum, cnt = 0;
	for (int i = 3, j; i <= n; ++i) {
        sum = 0;
        for (j = 1; j < i; ++j) {
            if (sum > a[i]) break;
            sum += a[j];
        }
        if (sum <= a[i]) continue;
        int k;
        for (int x = 0; x < j; ++x) {
            if (sum <= a[i]) break;
            k = 0;
            while (j + k <= i - x) {
                cnt = (cnt + pppc(i - 1 - x, j - 1 + k) + mod) % mod;
                ++k;
            }
            sum -= a[x];
        }
	}
	cout << cnt << endl;
	return 0;
}

inline int pppt(const int& num) {
    int ans = 1;
    for (int i = 2; i <= num; ++i) ans = (ans * i + mod) % mod;
    return ans;
}
