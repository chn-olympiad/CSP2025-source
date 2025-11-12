#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
const ll p = 998244353;

int n, m, c[N]; char s[N]; ll ans; bool st[N];

void find(int x, int y)
{
	if(n - y < m) return; if(x == n) {ans = (ans + 1) % p; return; }
	for(int i = 1; i <= n; i++) if(!st[i])
		{st[i] = 1; find(x + 1, y + (s[x + 1] == '0' || y >= c[i])); st[i] = 0; }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> (s + 1);
	for(int i = 1; i <= n; i++) cin >> c[i];
	find(0, 0); cout << ans;
	
	return 0;
}