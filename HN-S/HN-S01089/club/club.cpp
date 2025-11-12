#include <bits/stdc++.h>
using namespace std;
struct node{int a , b , c ;}a[100005];
bool cmp(node x,node y){return x.a>y.a;}
int t , n , dp[205][205] , dp2[50005] , ans ;
bool flag[2] ;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t ;
	while (t--)
	{
		flag[0]=flag[1]=1;
		cin >> n ;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			cin >> a[i].a >> a[i].b >> a[i].c ;
			if (a[i].b)flag[0]=0;
			if (a[i].c)flag[1]=0;
		}
		if (flag[0]&&flag[1])
		{
			sort(a+1,a+n+1,cmp);
			ans=0;
			for ( int i = 1 ; i <= n/2 ; i ++ )ans+=a[i].a;
			cout << ans ;
			continue;
		}
		if (flag[2])
		{
			
		}
		memset(dp,-0x3f,sizeof(dp));
		dp[0][0]=0;
		for ( int i = 1 ; i <= n ; i ++ )
		{
			for ( int j = min(i,n/2) ; j >= 0 ; j --  )
			{
				for ( int k = min(i-j,n/2) ; k >= 0 ; k -- )
				{
					dp[j][k]+=a[i].c;
					if (j>0)dp[j][k]=max(dp[j][k],dp[j-1][k]+a[i].a);
					if (k>0)dp[j][k]=max(dp[j][k],dp[j][k-1]+a[i].b);
				}
			}
		}
		ans=0;
		for ( int i = 0 ; i <= n/2 ; i ++ )for ( int j = n/2-i ; j <= n/2 ; j ++ )ans=max(ans,dp[i][j]);
		cout << ans << "\n" ;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
