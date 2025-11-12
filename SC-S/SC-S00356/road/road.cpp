#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
struct Node
{
	int u,v,w;
	Node(int _u=0,int _v=0,int _w=0):u(_u),v(_v),w(_w){}
	bool operator<(const Node &tmp)const
	{
		return w<tmp.w;
	}
}edge[M+N*10];
int n,m,k,father[N+15],a[15][N],siz;
long long ans;
int Find(int k)
{
	if(father[k]!=k) return father[k]=Find(father[k]);
	return k;
}
void solve1()
{
	ans=0x3f3f3f3f3f3f3f3f;
	siz=m;
	for(int sta=0;sta<(1<<k);sta++)
	{
		for(int i=1;i<=n+k;i++)
			father[i]=i;
		long long sum=0;
		for(int i=1;i<=k;i++)
		{
			if((sta>>(i-1))&1)
			{
				sum+=a[i][0];
				for(int j=1;j<=n;j++)
					edge[++siz]={n+i,j,a[i][j]};
			}
			
		}
		sort(edge+1,edge+siz+1);
		for(int i=1;i<=siz;i++)
		{
			int u=edge[i].u,v=edge[i].v,w=edge[i].w;
			int fu=Find(u),fv=Find(v);
			if(fu!=fv)
			{
				father[fu]=fv;
				sum+=1ll*w;
			}
		}
		ans=min(ans,sum);
		for(int i=m+1;i<=siz;i++)
			edge[i]={0,0,0};
		siz=m;
	}
	cout<<ans<<'\n';
}
void solve2()
{
	ans=0;
	siz=m;
	for(int i=1;i<=n+k;i++)
		father[i]=i;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			edge[++siz]={n+i,j,a[i][j]};
	sort(edge+1,edge+siz+1);
	for(int i=1;i<=siz;i++)
	{
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int fu=Find(u),fv=Find(v);
		if(fu!=fv)
		{
			father[fu]=fv;
			ans+=1ll*w;
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	bool spea=true;
	for(int i=1;i<=k;i++)
	{
		int cnt=0;
		for(int j=0;j<=n;j++)
		{
			cin>>a[i][j];
			if(j==0&&a[i][j]>0) spea=false;
			if(j>0&&a[i][j]==0) cnt++;
		}
		if(cnt==0) spea=false;
	}
	if(spea)
		solve2();
	else
		solve1();
	return 0;
}