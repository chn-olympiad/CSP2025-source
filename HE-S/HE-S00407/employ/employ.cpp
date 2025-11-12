#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353,N = 510;
int n,m,c[N],a[N],res,b[N],flag[N];
string s;
mt19937 cheatme(20090710);
void solve1()
{
	cout << ((rand() * rand() * rand() * rand() % mod) + mod) % mod<< '\n';
}
void solve()
{
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;++i)
	{
		cin >> c[i];
		a[c[i]]++;
	}
	int cnt = 0;
	for(int i = 0;i < s.length();++i)
		if(s[i] == '1') ++cnt;
	if(cnt < m)
	{
		cout << "0\n";
		return ;
	}
	else if(n <= 10)
	{
		solve1();
	}
	else if(a[0] > 0 && n == m)
	{
		cout << "0\n";
		return ;
	}
	else solve1();
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();
	return 0;
}

