#include<bits/stdc++.h>
using namespace std;
int a[100005],ans=0,v[100005][5],n;
void dfs(int s,int r)
{
	a[s]=r;
	if(s==n+1)
	{
		int ans1=0,an=0,bn=0,cn=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==1)an++;
			if(a[j]==2)bn++;
			if(a[j]==3)cn++;
		}
		if(an<=n/2&&bn<=n/2&&cn<=n/2)
		{
			for(int o=1;o<=n;o++)
			ans1+=v[o][a[o]];
			ans=max(ans,ans1);
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		dfs(s+1,i);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int tt;
cin>>tt;
for(int ttt=0;ttt<tt;ttt++)
{
	ans=0;
	memset(a,0,sizeof(a));
	memset(v,0,sizeof(v));
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=3;j++)
	cin>>v[i][j];
	dfs(0,0);
	cout<<ans<<endl;
}
	return 0;
}
