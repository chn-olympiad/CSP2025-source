//ll!!!!
#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define of(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define P_B push_back
const int inf=0x3f3f3f3f;
const ll INF=9e18;
const int N=1e4+10,M=1e7+10;
struct Edge 
{
	int u,v; ll w;
}e[M],e2[M];
bool cmp(Edge x,Edge y) {return x.w<y.w;}
ll c[20],a[20][N],fa[N];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	fo(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w;
	fo(i,1,k) {cin>>c[i]; fo(j,1,n) cin>>a[i][j];}
	bool flag=1;
	fo(i,1,k) if(c[i]) {flag=0; break;}
	//in
	if(k==0)
	{
		sort(e+1,e+m+1,cmp);
		fo(i,1,n) fa[i]=i;
		ll res=0;
		fo(i,1,m)
		{
			int u=e[i].u,v=e[i].v;
			int fa_u=find(u),fa_v=find(v);
			if(fa_u!=fa_v)
			{
				fa[fa_u]=fa_v;
				res+=e[i].w;
			}
		}
		cout<<res<<endl;
		return 0;
	}
	if(flag)
	{
		ll ans=0;
		int cnt_e=m;
		fo(id,1,k)
			fo(i,1,n)
				fo(j,i+1,n) {e[++cnt_e].u=i; e[cnt_e].v=j; e[cnt_e].w=a[id][i]+a[id][j];}
		sort(e+1,e+cnt_e+1,cmp);
		fo(i,1,n) fa[i]=i;
		fo(i,1,cnt_e)
			{
				int u=e[i].u,v=e[i].v;
				int fa_u=find(u),fa_v=find(v);
				if(fa_u!=fa_v)
				{
					fa[fa_u]=fa_v;
					ans+=e[i].w;
				}
			}
		cout<<ans<<endl;
	}
	if(m<=1e5)
	{
		ll ans=INF;
		for(int i=0;i<(1<<k)-1;++i)
		{
			ll res=0; int cnt_e=m;
			fo(i,1,m) {e2[i].u=e[i].u; e2[i].v=e[i].v; e2[i].w=e[i].w;}
			fo(j,0,k-1)
				if((1<<j)&i) 
				{
					int id=j+1;
					res+=c[id];
					fo(i,1,n)
						fo(j,i+1,n) {e2[++cnt_e].u=i; e2[cnt_e].v=j; e2[cnt_e].w=a[id][i]+a[id][j];}
				}
			sort(e2+1,e2+cnt_e+1,cmp);
			fo(i,1,n) fa[i]=i;
			fo(i,1,cnt_e)
			{
				int u=e2[i].u,v=e2[i].v;
				int fa_u=find(u),fa_v=find(v);
				if(fa_u!=fa_v)
				{
					fa[fa_u]=fa_v;
					res+=e2[i].w;
				}
			}
			ans=min(ans,res);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
in1:
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

out1:

*/
