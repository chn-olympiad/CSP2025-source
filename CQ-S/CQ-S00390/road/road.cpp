#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;

const int MAXN=10000+5;
int a[MAXN][MAXN],n,m,k,c,b[MAXN],fa[MAXN];

struct node
{
	int x,y,z;
}e[1100005];

bool cmp(node x,node y){return x.z<y.z;}

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void unionn(int x,int y)
{
	fa[find(x)]=find(y);
}

int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++) cin>>b[j];
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[j][k]) a[j][k]=a[k][j]=min(a[j][k],b[j]+b[k]+c);
				else a[j][k]=a[k][j]=b[j]+b[k]+c;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i][j]) e[++cnt].x=i,e[cnt].y=j,e[cnt].z=a[i][j];
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+cnt+1,cmp);
	int cur=0;
	ll sum=0;
	for(int i=1;i<=cnt;i++)
	{
		if(find(e[i].x)!=find(e[i].y))
		{
			++cur;sum+=1ll*e[i].z;
			unionn(e[i].x,e[i].y);
		}
		if(cur==n-1) return cout<<sum<<endl,0;
	}
	return 0;
}
//by Matrix_Power

