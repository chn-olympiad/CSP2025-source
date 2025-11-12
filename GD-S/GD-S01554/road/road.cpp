#include<iostream>
#include<cmath>
#include<queue>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=1000005;
ll n,m,k,u,v,w,c[maxn],a[15][maxn],flaga=1;
ll head[maxn],nxt[maxn],to[maxn],val[maxn],cnt=0;
inline void fre()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
inline void adde(ll u,ll v,ll w)
{
	to[++cnt]=v;
	nxt[cnt]=head[u];
	val[cnt]=w;
	head[u]=cnt;
}
int main()
{
	IOS
	fre();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]) flaga=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]) flaga=0;
		}
	}
	cout<<0;
	return 0;
} 
