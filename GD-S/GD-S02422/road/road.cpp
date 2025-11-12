#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+5,N=1e4+5;
int n,m,k,c[15],a[15][N],f[N],ans=INT_MAX;
struct edge{
	int u,v,w;
	friend bool operator <(edge x,edge y)
	{
		return x.w<y.w;
	}
}e[M],l[15];
int find(int x)
{
	return f[x]=f[x]==x?x:find(f[x]);
}
int sol(int t[])
{
	int res=0;
	for(int i=1;i<=n;i++) l[i]={0,i,t[i]};
	sort(l+1,l+1+n);
//	cout<<"\n";
//	for(int i=1;i<=n;i++) cout<<l[i].u<<" "<<l[i].v<<" "<<l[i].w<<endl;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int j=1,i=1;i<=m||j<=n;)
	{
		int u,v,w;
		if(i<=m&&(j>n||e[i].w<l[j].w))
		{
			u=e[i].u,v=e[i].v,w=e[i].w;
			i++;
		}
		else
		{
			u=l[j].u,v=l[j].v,w=l[j].w;
			j++;
		}
		if(find(u)==find(v)) continue;
		f[find(u)]=find(v);
		res+=w;
	}
	return res;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m);
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	int t[N];
	for(int i=1;i<(1<<k);i++)
	{
		for(int j=1;j<=n;j++) t[j]=0x3f;
		int sum=0;
		for(int j=1;j<=k;j++)
		{
			if((i>>(j-1))&1==1)
			{
				for(int y=1;y<=n;y++) t[y]=min(t[y],a[j][y]);
				sum+=c[j];
			}
		}
		ans=min(ans,sum+sol(t));
	}
	cout<<ans;
	return 0;
}
