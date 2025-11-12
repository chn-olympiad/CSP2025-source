#include<bits/stdc++.h>//zui xiao sheng cheng shu
using namespace std;
int to[1200005*2],nxt[1200005*2],h[10055],val[1200005*2];
int cnt;
unsigned long long dis[10055];
int exdis[55];
int exvis[55];
int lesdisfrom[10055];
bool vis[10055];
#define inf 9223372036854775806*9ull
inline void add(int u,int v,int w)// lian shi qian xiang xing
{
	to[++cnt]=v;
	val[cnt]=w;
	nxt[cnt]=h[u];
	h[u]=cnt;
	return;
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cout.tie(0);
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	int n,m,k;
 	cin >> n >> m >> k;
 	int a,b,c;
 	for(int i = 1;i<=n+k;i++)
 	{
 		dis[i]=inf;
	 }
	 dis[1] = 0;
 	for(int i = 1;i<=m;i++)
 	{
 		cin >> a >> b >> c;
		add(a,b,c);
		add(b,a,c);
	}
	for(int i = 1;i<=k;i++)
	{
		cin >> exdis[i];
		for(int j = 1;j<=n;j++)
		{
			cin >> c;
			add(n+i,j,c);
			add(j,n+i,c);
		}
	}
		unsigned long long ans = 0;
		while(1){
		int p = 0;
		unsigned long long mxdis=inf;
		for(int i = 1;i<=n+k;i++)
		{
			if(dis[i]<mxdis&&!vis[i])
			{
				p=i;
				mxdis = dis[i];
			}
		}
		if(p == 0)break;
		ans+=dis[p];
		for(int i = h[p];i;i=nxt[i])
		{
			if(!vis[to[i]])
			{
				int exd = (to[i]>n?exdis[to[i]-n]:0);
				if(dis[p]+val[i]+exd<dis[to[i]])
				{
					dis[to[i]] = dis[p]+val[i]+exd;
					if(lesdisfrom[to[i]]>n)
					{
						exvis[lesdisfrom[to[i]]-n]--;
						lesdisfrom[to[i]]=p;
						if(p>n) exvis[p]++;
					}
				}
			}
		}
		vis[p] = 1;
	}
	for(int i = 1;i<=k;i++)
	{
		if(exvis[i]==0)
		{
			ans-=dis[i+n];
		}
	}
	cout << ans;
	return 0;
}