#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
const int N=1e4+5;
int n,m,k,fa[N];
lo res=LONG_LONG_MAX,sum,mp[N][N],remp[N][N];
bool fl=1;
struct Vill{int c;int a[N];}vill[15];
int Find(lo x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
struct Edge{lo u,v,w;Edge(lo u,lo v,lo w):u(u),v(v),w(w){}bool operator<(const Edge&an)const{return w<an.w;};};
vector<Edge>ve;
void MST()
{
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)ve.emplace_back(i,j,remp[i][j]);
	iota(fa+1,fa+n+1,1);
	sort(ve.begin(),ve.end());
	for(auto i:ve)
	{
		int u=Find(i.u),v=Find(i.v),w=i.w;
		if(u!=v)fa[u]=v,sum+=w;
	}
	while(!ve.empty())ve.pop_back();
}
int main()
{
//	freopen("road.in","r",stdin);
////	freopen("road2.in","r",stdin);
//	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	memset(mp,0x3f,sizeof(mp));
	memset(remp,0x3f,sizeof(remp));
	for(lo i=1,u,v,w;i<=m;++i)cin>>u>>v>>w,remp[u][v]=remp[v][u]=mp[u][v]=mp[v][u]=min(mp[u][v],w);
	for(int i=1;i<=k;++i)
	{
		cin>>vill[i].c;fl&=(!vill[i].c);
		for(int j=1;j<=n;++j)cin>>vill[i].a[j];
	}
	if(fl)
	{
		for(int i=1;i<=k;++i)for(int j=1;j<=n;++j)for(int k=j+1;k<=n;++k){remp[j][k]=remp[k][j]=min(remp[j][k],(lo)vill[i].a[j]+vill[i].a[k]);}
		MST();
		res=sum;
	}
	else if(!k)MST();
	else
	{
		for(int gm=0;gm<(1<<k);++gm)
		{
			sum=0;
			for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)remp[i][j]=remp[j][i]=mp[i][j];
			for(int i=1;i<=k;++i)if((gm>>(i-1))&1)
			{
				for(int j=1;j<=n;++j)for(int k=j+1;k<=n;++k)remp[j][k]=min(remp[j][k],(lo)vill[i].a[j]+vill[i].a[k]);
				sum+=vill[i].c;
			}
			MST();
			res=min(res,sum);
		}
	}
	cout<<res;
}
//555²ËËÀÁË 
