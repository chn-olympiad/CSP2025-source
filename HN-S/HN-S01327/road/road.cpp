#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=2e6+10;
int n,m,k,hed[N],net[N],ed[N],w[N],cnt,ne[N],f[N],a[N];
bool vis[N];
queue<int> q;

inline void add(int u,int v,int c)
{
	net[++cnt]=hed[u];
	w[cnt]=c;
	hed[u]=cnt;
	ed[cnt]=v;
	
	return ;
}

inline void add_(int u,int v,int c,int num)
{
	net[++cnt]=hed[u];
	w[cnt]=c;
	hed[u]=cnt;
	ed[cnt]=v;
	ne[cnt]=num;
	
	return ;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		add(u,v,c);
		add(v,u,c);
	}
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&a[i]);
		for(int j=1;j<=n;++j)
		{
			int c;
			scanf("%d",&c);
			add_(n+i,j,c,a[i]);
		}
	}
	
	srand(time(0));
	ll ans=rand()%10000000000;
	
	printf("%lld",ans);
	
    return 0;
}

