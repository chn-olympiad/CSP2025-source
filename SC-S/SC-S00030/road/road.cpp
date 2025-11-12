#include<bits/stdc++.h>
#define maxn 1200000
#define inf 12000
#define qwq return
#define int long long
using namespace std;
int n,m,k;
int city[inf][inf];//表示两城市间的距离 
int vall[12][inf];//表示乡村到每个城市的距离 
int book[inf],fa[inf];
struct node
{
	int from;
	int w;
	int next;
	int to;
}e[maxn];
int cnt=0;
int head[inf];
void adde(int x,int y,int w)
{
	cnt++;
	e[cnt].w=w;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
bool cmp(node x,node y){qwq x.w<y.w;}
int look(int x)
{
	if(fa[x]!=x)fa[x]=look(fa[x]);
	return fa[x];
}
int krustral()
{
	int ans=0;
	int z=0;//计数 
	for(int i=1;i<=cnt;i++)
	{
		int u=e[i].from;
		int v=e[i].to;
		if(look(u)==look(v))continue;
		fa[u]=v;
		ans+=e[i].w;
		if(!book[u])
		{
			z++;
			book[u]=1;
		}
		if(!book[v])
		{
			z++;
			book[v]=1;
		}
		if(z==n)return ans;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(city,0x7f,sizeof(city));
	for(int i=1;i<=n;i++)fa[i]=i;
	int a,b,c;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		city[min(a,b)][max(a,b)]=c;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>vall[i][j];
			for(int ij=1;ij<j;ij++)
			{
				city[ij][j]=min(city[ij][j],vall[i][j]+vall[i][ij]+c);
				adde(ij,j,city[ij][j]);
//				adde(ij,j,city[j][ij]);
			}
		}
	}
	sort(e+1,e+cnt+1,cmp);
	cout<<krustral();
	qwq 0;
}