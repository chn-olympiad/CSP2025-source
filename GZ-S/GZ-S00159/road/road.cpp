//GZ-S00159 北京师范大学贵阳附属中学 张景奕 
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+51,M=1e6+7+N*10;
typedef long long ll;
typedef pair<ll,int> pli;
int n,m,k;
	bool ms=1;
struct len{
	int p,q;
	ll w;
	int ty;
}l[M];
bool cmpl(len a,len b)
{
	return a.w<b.w;
}
ll u[11][N];
int f[N],si[N];
int fa(int u)
{
	if(u!=f[u]) f[u]=fa(f[u]);
	return f[u];
}
inline bool join(int p,int q)
{
	p=fa(p),q=fa(q);
	if(p==q) return 0;
	if(si[p]<si[q]) swap(p,q);
	si[p]+=si[q];
	f[q]=p;
	return 1;
}
ll ans=0;
ll init(int n,int m)
{
	ll res=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=i,si[i]=1;
	}
	for(int i=1,g=0;g<n-1&&i<m;i++)
	{
		if(join(l[i].p,l[i].q))
		{
			res+=l[i].w;
			g++;
		}
	}
	return res;
}
bitset <N> use[11];
void work()
{
	for(int i=1;i<(1<<k);i++)
	{
		ll tmp=0;
		int cnt=m+1;
		int node=n+1;
		for(int j=1,b=1;j<=k;j++,b<<=1)
		{
			if(!(i&b)) continue;
			tmp+=u[j][0];
			for(int q=1;q<=n;q++)
			{
				if(u[j][q])
				{
					l[cnt++]={node,q,u[j][q],0};
				}
			}
			node++;
		}
		if(tmp>=ans) continue;
		sort(l+1,l+cnt,cmpl);
		tmp+=init(node-1,cnt);
		if(tmp<ans) ans=tmp;
	}
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>l[i].p>>l[i].q>>l[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>u[i][0];
		if(ms&&u[i][0]) ms=0;
		for(int j=1;j<=n;j++)
		{
			cin>>u[i][j];
		}
	}
	if(ms)
	{
		int cnt=m+1;
		for(int i=1;i<=k;i++)
		{
			int p=-1; 
			for(int j=1;j<=n;j++)
			{
				if(!u[i][j])
				{
					p=j;
					break;
				}
			}
			for(int q=1;q<=n;q++)
			{
				if(u[i][q])
				{
					l[cnt++]={p,q,u[i][q],0};
				}
			}
		}
		sort(l+1,l+cnt,cmpl);
	}
	if(!ms) sort(l+1,l+m+1,cmpl);
	if(ms)
	{
		cout<<init(n,M);
		return 0;
	}
	ans=init(n,M);
	work();
	return 0;
}
