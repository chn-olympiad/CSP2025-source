#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
struct node
{
	int x,y,w;
	friend bool operator < (node a,node b)
	{
		return a.w<b.w;
	}
}a[M],b[M];
int n,m,k,c[N],cnt,fa[N],sz[N];
int find(int u)
{
	if(fa[u]==u)return u;
	else return (fa[u]=find(fa[u]));
}
bool hb(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y)
	{
		if(sz[x]<=sz[y])
		{
			fa[x]=y;
			sz[y]+=sz[x];
		}
		else
		{
			fa[y]=x;
			sz[x]+=sz[y];
		}
		return true;
	}
	return false;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>b[i].x>>b[i].y>>b[i].w;
	cnt=m;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int w;cin>>w;
			b[++cnt]={i+n,j,w};
		}
	}
	sort(b+1,b+1+cnt);long long ans;
	for(int s=0;s<(1<<k);s++)
	{
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=n+k;i++)sz[i]=1;
		int res=0,d=0;long long sum=0;
		for(int i=1;i<=k;i++)if(s>>(i-1)&1)sum+=c[i],d++;
		for(int i=1;i<=cnt&&res<n-1+d;i++)
		{
			if(b[i].x>n&&!(s>>(b[i].x-n-1)&1))continue;
			//cout<<b[i].x<<" "<<b[i].y<<" "<<b[i].w<<"|\n";
			if(hb(b[i].x,b[i].y))
			{
				sum+=b[i].w;
				res++;
			}
		}
		//cout<<res<<" "<<sum<<"\n";
		if(s)ans=min(ans,sum);
		else ans=sum;
	}
	cout<<ans;
	return 0;
}