#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,ans,num[100005][3];
void dfs(int u,int a,int b,int c,int cnt)
{
	if(u==n)
	{
		ans=max(ans,cnt);
		return;
	}
	for(int i=0;i<3;i++)
	{
		if(i==0&&a<n/2)dfs(u+1,a+1,b,c,cnt+num[u][0]);
		else if(i==1&&b<n/2)dfs(u+1,a,b+1,c,cnt+num[u][1]);
		else if(c<n/2)dfs(u+1,a,b,c+1,cnt+num[u][2]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++)cin>>num[i][0]>>num[i][1]>>num[i][2];
		dfs(0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
