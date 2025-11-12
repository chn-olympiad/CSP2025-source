#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][4],ans,sum,f[100001],c1,c2,c3;
void dfs(int p,int b1,int b2,int b3)
{
	if(p==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(b1+1<=n/2)
	{
		sum+=a[p][1];
		dfs(p+1,b1+1,b2,b3);
		sum-=a[p][1];
	}
	if(b2+1<=n/2)
	{
		sum+=a[p][2];
		dfs(p+1,b1,b2+1,b3);
		sum-=a[p][2];
	}
	if(b3+1<=n/2)
	{
		sum+=a[p][3];
		dfs(p+1,b1,b2,b3+1);
		sum-=a[p][3];
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
		dfs(1,0,0,0);
		cout<<ans<<'\n';
		ans=sum=0;
	}
}
