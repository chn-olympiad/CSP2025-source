#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353 ;
int n , m , a[505] , ans , dp[300005][20] ;
bool f[505] ;
string s ;
int lowbit(int x){return x&-x;}
int popcnt(int x)
{
	int cnt = 0 ;
	while (x)
	{
		cnt++;
		x-=lowbit(x);
	}
	return cnt;
}
void dfs(int step,int cnt)
{
	if (step>n)
	{
		if (cnt>=m)
		{
			++ans;
			ans%=mod;
		}
		return;
	}
	for ( int i = 1 ; i <= n ; i ++ )
	{
		if (f[i])continue;
		f[i]=1;
		dfs(step+1,cnt+(s[step]=='1'&&step-cnt-1<a[i]));
		f[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s ;
	s=" "+s;
	for ( int i = 1 ; i <= n ; i ++ )cin >> a[i] ;
	dfs(1,0);
	cout << ans ;
	return 0;
}
