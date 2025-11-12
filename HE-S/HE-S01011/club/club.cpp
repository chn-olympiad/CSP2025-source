#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool u;
int club1[100005],club3[100005],club2[100005],ans,n,maxn,tres;
long long clubs[4];
bool vis[100005];
bool cmp(int m,int n)
{
	return m>n;
}
void dfs(int ti,int n)
{
	if(ti==n+1)
	{
		ans=max(ans,tres); 
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(!vis[ti])
		{
			if(i==1 && club1[0]<n/2)
			{
				tres+=club1[ti];
				vis[ti]=1;
				club1[0]++;
				dfs(ti+1,n);
				club1[0]--;
				tres-=club1[ti];
				vis[ti]=0;
			}
			if(i==2 && club2[0]<n/2)
			{
				tres+=club2[ti];
				vis[ti]=1;
				club2[0]++;
				dfs(ti+1,n);
				tres-=club2[ti];
				club2[0]--;
				vis[ti]=0;
			}
			if(i==3 && club3[0]<n/2)
			{
				tres+=club3[ti];
				vis[ti]=1;
				club3[0]++;
				dfs(ti+1,n);
				club3[0]--;
				tres-=club3[ti];
				vis[ti]=0;
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ques;cin>>ques;
	for(int i=1;i<=ques;i++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>club1[i]>>club2[i]>>club3[i];
			if(club2[i]!=0 || club3[i]!=0){u=1;}
		
		} 
		if(!u)
		{
			ans=0;
			sort(club1+1,club1+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=club1[i];
			}
			cout<<ans<<'\n';
		}
		if(u)
		{
			ans=0;
			dfs(1,n);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
