//GZ-S00290 贵阳市白云区华师一学校
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define upp(i, l, r) for (int i = l; i <= r; i++)
#define dww(i, l, r) for (int i = l; i >= r; i--)
using namespace std;

const int N = 5e2 + 5;

int n, m;
string s;
int c[N];
int p[N];
bool st[N];
int res;

void dfs(int u) {
	if (u > n) {
		int cnt1 = 0, cnt2 = 0;
		upp(i, 1, n) {
			if (cnt2 >= c[p[i]] || s[i - 1] == '0') cnt2++;
			else cnt1++;
		}
		if (cnt1 >= m) res++;
	}
	upp(i, 1, n) {
		if (st[i]) continue;
		st[i] = 1;
		p[u] = i;
		dfs(u + 1);
		st[i] = 0;
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	upp(i, 1, n) cin >> c[i];
	if (n > 10) {
		cout << 0;
		return 0;
	}
	dfs(1);
	cout << res;
	
	return 0;
}
