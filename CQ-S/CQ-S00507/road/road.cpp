#include<bits/stdc++.h>
using namespace std;
long long fa[100010],kt[100],mp[10001][10001],kf[100],mp1[15][10001];
long long n,m,k,ans=0;
struct ed
{
	long long u,v,w;
};
vector<ed> e;
long long find(long long x)
{
	if(fa[x]==x)return x;
	long long t=find(fa[x]);
	fa[x]=t;
	return t;
}
bool cmp(ed a,ed b)
{
	return a.w<b.w;
}
void mst()
{
	long long cnt=0;
	sort(e.begin(),e.end(),cmp);
	for(long long i=0;i<e.size();i++)
	{
		long long x=find(e[i].u),y=find(e[i].v);
		if(x!=y)
		{
			ans+=e[i].w;
			cnt++;
			fa[x]=y;
		}
		if(cnt>n)break;
	}
	for(long long i=0;i<k;i++)if(!kt[i])ans+=kf[i];
	cout<<ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=0;i<=n;i++)fa[i]=i;
	for(long long i=0;i<k;i++)kt[i]=1;
	for(long long i=0;i<n;i++)
		for(long long j=0;j<n;j++)mp[i][j]=INT_MAX;
	for(long long i=0;i<m;i++)
	{
		long long u,v,w;
		cin>>u>>v>>w;
		mp[u-1][v-1]=min(w,mp[u-1][v-1]);
		mp[v-1][u-1]=min(w,mp[v-1][u-1]);
	}
	for(long long i=0;i<k;i++)
	{
		long long w;
		cin>>kf[i];
		for(long long j=0;j<n;j++)
		{
			cin>>w;
			mp1[i][j]=w;
		}
	}
	for(long long i=0;i<100;i++)kt[i]=1;
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<n;j++)
		{
			if(i==j)continue;
			for(long long q=0;q<k;q++)
			{
				if(mp[i][j]>=mp1[q][i]+mp1[q][j])
				{
					mp[i][j]=mp1[q][i]+mp1[q][j];
					kt[q]=mp[i][j]-mp1[q][i]-mp1[q][j];
				}
			}
		}
	}
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<n;j++)
		{
			if(i==j)continue;
			e.push_back({i,j,mp[i][j]});
		}
	}
	mst();
	return 0;
}

