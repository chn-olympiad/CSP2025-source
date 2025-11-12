//GZ-S00288 贵阳市第一中学 殳晟欢
#include<bits/stdc++.h>
using namespace std;
int t,n,m,ans,c1,c2,a[4],dp[201][4][101];
struct node
{
	int x,y;
}b[100001];
bool cmp(node ax,node sx)
{
	return max(ax.x,ax.y)>max(sx.x,sx.y);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
//		cin>>n;
//		for(int i=1;i<=n;i++)
//		{
//			cin>>a[1]>>a[2]>>a[3];
//			for(int j=1;j<=3;j++)
//			{
//				for(int k=1;k*2<=n;k++)
//				{
//					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[j]);
//					cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
//				}
//			}
//		}
//		for(int i=1;i<=3;i++)
//		{
//			cout<<dp[n][i][n/2]<<' ';
//		}
		cin>>n;
		ans=0,c1=0;
		for(int i=1;i<=n;i++)
		{
			cin>>b[i].x>>b[i].y>>m;
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(b[i].x>b[i].y && c1<=n/2)
				ans+=b[i].x,c1++;
			else
				ans+=b[i].y;
		}
		cout<<ans<<endl;
	}
	return 0;
}
