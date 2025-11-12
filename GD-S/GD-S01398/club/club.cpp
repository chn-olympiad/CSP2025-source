#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll M=1e5+5,N=105;
ll T,n,a[M][4],dp[2][N][N],b[M];
bool tag=0,fl=1;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		fl=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0)
			{
				fl=0;
			}
			b[i]=a[i][1];
		}
		if(fl)
		{
			ll ans=0;
			sort(b+1,b+1+n);
			for(int i=1;i<=n/2;i++)
			{
				ans+=b[n/2+i];
			}
			cout<<ans<<endl;
			continue;
		}
		memset(dp,0,sizeof(dp));
		dp[tag][1][0]=a[1][1];
		dp[tag][0][1]=a[1][2];
		dp[tag][0][0]=a[1][3];
		for(ll i=2;i<=n;i++)
		{
			tag^=1;
			for(ll j=0;j<=min(i,n/2);j++)
			{
				for(ll k=0;k<=min(i,n/2);k++)
				{
					if(j+k>i) break;
					ll w=i-j-k;
					if(w>n/2) continue;
					ll o1=0,o2=0,o3=0;
					if(j) o1=dp[tag^1][j-1][k]+a[i][1];
					if(k) o2=dp[tag^1][j][k-1]+a[i][2];
					if(w) o3=dp[tag^1][j][k]+a[i][3];
					dp[tag][j][k]=max(o1,max(o2,o3));
				}
			}
		}
		ll ans=0;
		for(ll j=0;j<=n/2;j++)
		{
			for(ll k=0;k<=n/2;k++)
			{
				if(j+k>n) break;
				ll w=n-j-k;
				if(w>n/2) continue;
				ans=max(ans,dp[tag][j][k]);
			}
		}
		cout<<ans<<endl;
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
