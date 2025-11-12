#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
struct edge{
	int u,v,w;
}e[2000005];
int n,m,k,c[N],a[K][N],fa[N],id,jihuo[K],jihuozhe[K];
int trovi(int x)
{
	if(x==fa[x])return x;
	return fa[x]=trovi(fa[x]);
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
void dudek()
{
	sort(e+1,e+id+1,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=id;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(cnt==n-1)break;
		if(fa[trovi(u)]==trovi(v))continue;
		fa[trovi(u)]=trovi(v);
		cnt++;
		ans+=w;
	}
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool flag=1;
	id=m;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		jihuo[i]=0;
		cin>>c[i];
		if(c[i]!=0)flag=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			e[++id].u=i+n;
			e[id].v=j;
			e[id].w=a[i][j]+c[i];
		}
	}
	if(k==0)
	{
		dudek();
		return 0;
	}
	/*for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			for(int kk=1;kk<=k;k++)
			{
				e[++id].u=i;
				e[id].v=j;
				e[id].w=a[kk][i]+a[kk][j];
			}
		}
	if(flag)
	{
		dudek();
		return 0;
	}*/	
	sort(e+1,e+id+1,cmp);
	long long cnt=0,ans=0;
	for(int i=1;i<=id;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(cnt>=n-1)break;
		if(fa[trovi(u)]==trovi(v))continue;
		if(u>n)
		{
			if(!jihuo[u-n])
			{
				jihuo[u-n]=1;
				ans+=w;
				jihuozhe[u-n]=v;
			}
			else
			{
				jihuo[u-n]++;
				cnt++;
				ans+=w-c[u-n];
			}
			fa[trovi(u)]=trovi(v);
		}
		else{
			fa[trovi(u)]=trovi(v);
			cnt++;
			ans+=w;
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(jihuo[i]==1)ans-=(a[i][jihuozhe[i]]+c[i]);
	}
	cout<<ans;
	return 0;
}
