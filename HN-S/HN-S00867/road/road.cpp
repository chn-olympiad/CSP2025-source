#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,k;
int ans=1e9,M;
int fa[N],C[N];
struct node
{
	int x,y,w;
}a[N];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void unionn(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
		fa[x]=y;
}
void kruskal(int x)
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(a+1,a+M+x*n+1,cmp);
	int sum=C[n+x],cnt=0;
	for(int i=1;i<=M+x*n;i++)
	{
		if(find(a[i].x)!=find(a[i].y))
		{
			unionn(a[i].x,a[i].y);
			sum+=a[i].w;
			cnt++;
			if(cnt>n+x-1)
				break;
		}
	}
	if(cnt>=n+x-1)
		ans=min(ans,sum);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	M=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[++M].x=u;
		a[M].y=v;
		a[M].w=w;
	}
	for(int j=n+1;j<=n+k;j++)
	{
		int c;
		cin>>c;
		C[j]=c;
		for(int i=1;i<=n;i++)
		{
			int v;
			cin>>v;
			a[M+(j-n-1)*n+i]={j,i,v};
		}
	}
	kruskal(0);
	for(int i=1;i<=k;i++)
	{
		if(C[n+i]>=ans)
			continue;
		kruskal(i);
	}
	cout<<ans;
    return 0;
}

