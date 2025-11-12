#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;

const int N = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const ll mod = 998244353;

int n, m;
int c[N], p[N];
string s;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> c[i], p[i] = i;
	int ans = 0;
	do{
		int cnt = 0, res = 0;
		for (int i = 1; i <= n; i++){
			if (cnt >= c[p[i]]) {cnt++; continue;}
			if (s[i - 1] == '0') cnt++;
			else res++;
		}
		if (res >= m) ans++;
	}while (next_permutation(p + 1, p + n + 1));
	cout << ans % mod;
	return 0;
}

