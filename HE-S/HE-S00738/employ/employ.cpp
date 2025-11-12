#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL N = 5e2 + 52, mod = 998244353;
LL n, m, a[N], ans;
string s;
bool f[N];
LL Num(LL k)
{
	LL mul = 1;
	while(k) 
	{
		mul = mul * k % mod;
		k--;
	}
	return mul;
}
void dfs(LL now, LL cnt, LL num)
{
	if(num == m)
	{
		ans = (ans + Num(n - now + 1)) % mod;
		return;
	}
	if(now > n || n - now + 1 + num < m) return;
	for(LL i = 1; i <= n; i++)
	{
		if(f[i]) continue;
		f[i] = 1;
		if(a[i] > cnt && s[now] == '1') dfs(now + 1, cnt, num + 1);
		else dfs(now + 1, cnt + 1, num);
		f[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = " " + s;
	for(LL i = 1; i <= n; i++) cin >> a[i];
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}
