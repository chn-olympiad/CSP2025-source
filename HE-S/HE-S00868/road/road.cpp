#include<bits/stdc++.h>

using namespace std;
long long tu[10001][10001]={},has_done=1,ans=0,bian=0;
long long ans1[100001]={},n,m,k,u,v,w,c[11],a[11][10001]={};
bool q[1000001]={};
void dfs(long long l)
{
	if(has_done>=n)
	{
		bian++;
		ans1[bian]=ans;
		return ;
	}
	for(long long i=1;i<=n;i++)
	{
		if(q[i]!=1 and tu[l][i]!=0)
		{
			ans+=tu[l][i];
			q[i]=1;
			has_done++;
			dfs(i);
			has_done--;
			q[i]=0;
			ans-=tu[l][i];
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		long long miin=INT_MAX,begin;
		for(long long i=1;i<=m;i++)
		{
			
			cin>>u>>v>>w;
			miin=min(miin,w);
			if(miin==w)
			{
				begin=u;
			}
			tu[u][v]=w;
			tu[v][u]=w;
		}
		dfs(begin);
		sort(ans1+1,ans1+1+bian);
		for(long long i=1;i<=bian;i++)
		{
			if(ans1[i]!=0)
			{
				cout<<ans1[i]<<endl;
				return 0;
			}
			else
			{
				continue;
			}
		}
	}
	for(long long i=1;i<=m;i++)
	{
		cin>>u>>v>>m;
		tu[u][v]=w;
		tu[v][u]=w;
	}
	int p=0;
	for(long long i=1;i<=k;i++)
	{
		
		cin>>c[i];
		if(c[i]==0)
		{
			p++;
		}
		int j=1;
		while(j<=n)
		{
			cin>>a[i][j];
			j++;
		}
	}
	if(p==k)
	{
		cout<<0;
		return 0;
	}
	
	return 0;
}



