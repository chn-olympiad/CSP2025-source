#include<bits/stdc++.h>
#define ll long long
#define Int __int128
#define pb push_back
#define rep(i , a , b) for (int i = (a); i <= (b); i++)
#define drep(i , a , b) for (int i = (a); i >= (b); i--)
using namespace std;
const int maxn = 2e6+5;
int n , k , a[maxn] , s[maxn] , dp[maxn] , ans , g[maxn];
signed main()
{
//	freopen("xor.in" , "r" , stdin);
//	freopen("xor.out" , "w" , stdout);
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> k;
	rep(i , 1 , n)cin >> a[i],s[i]=s[i-1]^a[i];
	memset(g , -1 , sizeof(g));
	g[0]=0;
	rep(i , 1 , n)
	{
		dp[i]=g[s[i]^k]+1;
		dp[i]=max(dp[i] , dp[i-1]);
		g[s[i]]=dp[i];
		ans=max(ans , dp[i]);
		
	}
	cout << ans << "\n";
	return 0;
}

/*
mem file time
author: YBTL sjwhsss RP++
贪心，dp，构造，二分，随机化，哈希，图论建模，根号分治，分块，分治，线段树分治，扫描线
*/