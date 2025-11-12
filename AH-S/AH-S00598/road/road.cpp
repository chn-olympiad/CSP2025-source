#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N=1e6+5;
int i,j,n,m,k,fa[N],fl[N],cnt,ans,wit[N],wit2[N],wit3[N],wit4[N],fa2[N],sum2[N],ro,sum[N],tttt[N],tttt2[N];
struct edge
{
	int u,v,w;
}g[N];
struct city
{
	int cos,to[N],val[N];
}c[15];
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int find2(int x)
{
	if(x==fa2[x])return x;
	return fa2[x]=find(fa2[x]);
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)fa[i]=i,wit[i]=-1;
	for(i=1;i<=m;i++)cin>>g[i].u>>g[i].v>>g[i].w;
	for(i=1;i<=k;i++)
	{
		cin>>c[i].cos;
		for(j=1;j<=n;j++)
		{
			c[i].to[j]=j;
			cin>>c[i].val[j];
		}
	}
	sort(g+1,g+m+1,cmp);
	for(i=1;i<=m;i++)
	{
		int x=find(g[i].u),y=find(g[i].v);
		if(x==y)continue;
		fa[x]=y,ans+=g[i].w,wit[x]=g[i].w,wit3[x]=max(wit3[x],g[i].w),cnt++;
	}
	for(i=1;i<=n;i++)if(fa[i]==i)ro=i;
	//cout<<ans<<endl;
	
	
	
	for(i=1;i<=k;i++)
	{
		int mi=INT_MAX,ans2=ans+c[i].cos,k=-1,shushu=0;
		for(j=1;j<=k;j++)sum2[i]=sum[i];
		for(j=1;j<=n;j++)
		{
			wit2[j]=wit[j],wit4[j]=wit3[j],tttt2[j]=tttt[j];
			if(wit[j]-c[i].val[j]<mi&&wit[j]-c[i].val[j]>0)k=j,mi=wit[j]-c[i].val[j];
			if(ro==j)
			{
				if(wit3[j]-c[i].val[j]<mi&&wit3[j]-c[i].val[j]>0)k=j,mi=wit3[j]-c[i].val[j];
			}
		}
		if(k==-1)continue;
		shushu++;
		if(k==ro)wit2[k]=c[i].val[k],ro=n+i;
		//else wit2[k]=c[i].val[k];
		ans2+=c[i].val[k],tttt[k]=i;
		//cout<<k<<' '<<ans2<<endl;
		for(j=1;j<=n;j++)
		{
			int yuan=tttt[j];
			if(j==k)continue;
			if(wit2[j]-c[i].val[j]>0)ans2-=(wit2[j]-c[i].val[j]),shushu++,sum2[yuan]--,tttt2[j]=i;
			if(j==ro)
			{
				if(wit4[j]-c[i].val[j]>0)
				{
					ans2-=(wit4[j]-c[i].val[j]);
					ro=n+i,wit2[k]=c[i].val[k],ro=n+i,shushu++,sum2[yuan]--,tttt2[j]=i;
				}
			}
			if(sum2[yuan]==0&&yuan!=0)ans2-=c[yuan].cos;
		}
		if(ans2<ans)
		{
			ans=ans2,sum2[i]=shushu;
			for(j=1;j<=n;j++)wit[j]=wit2[j],wit3[j]=wit4[j],tttt[j]=tttt2[j];
			for(j=1;j<=k;j++)sum[i]=sum2[i];
		}
	}
	cout<<ans;
	return 0;
}
