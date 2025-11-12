#include<bits/stdc++.h>
#define ll long long
#define Int __int128
#define pb push_back
#define rep(i , a , b) for (int i = (a); i <= (b); i++)
#define drep(i , a , b) for (int i = (a); i >= (b); i--)
using namespace std;
const int maxn = 5e3+5 , mod = 998244353;
int n , m , a[maxn] , mx;
ll ans , dp[maxn][maxn] , g[maxn];
void upd(ll &a , ll b){a=((a+b)%mod+mod)%mod;}
ll qpow(ll a , ll b)
{
	ll res = 1;
	while(b)
	{
		if (b & 1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
signed main()
{
//	freopen("polygon.in" , "r" , stdin);
//	freopen("polygon.out" , "w" , stdout);
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(i , 1 , n)cin >> a[i],mx=max(mx , a[i]);
	sort(a + 1 , a + n + 1);
	dp[0][0]=1;
	g[0]=1;
	rep(i , 1 , n)
	{
		rep(j , 0 , mx)upd(dp[i][j] , g[j]);
		rep(j , a[i] , mx)upd(g[j],dp[i][j-a[i]]);
		rep(j , 0 , a[i])upd(ans , dp[i][j]);
	}
	cout << ((qpow(2,n)-ans-1)%mod+mod)%mod << "\n";
	return 0;
}

/*
mem file time
author: YBTL sjwhsss RP++
n^2 100pts
10:20 It seems that I AK CSP-J 2025!!!
贪心，dp，构造，二分，随机化，哈希，图论建模，根号分治，分块，分治，线段树分治，扫描线
*/