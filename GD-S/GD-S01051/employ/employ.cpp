#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=501, Mod=998244353;
int a[N], ans;
void dfs(int n, int deep, int now, int r)
{
	if(deep==n)
	{
		ans++;
		return ;
	}
	if(now==r)
		return ;
	for(int i=1;now+i<=r;i++)
		dfs(n, deep+1, now+i, r);
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=m;i<=n;i++)
		dfs(i, 0, 0, n);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
100 99
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19
*/
