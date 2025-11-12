#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define bll __int128
#define vii vector<int>
#define pb push_back
#define ppb pop_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define fi first
#define sec second
#define Qii queue<int>
#define vll vector<ll>
#define vpi vector<pii>
#define ci const int
using namespace std;
const int N=1e6+5,M=1e4+5,K=15;
int fa[M+K],c[K],a[K][M];
int n,m,k,mm;
struct Edge{int x,y,z;}E[N],e[N];
int find(int x){if(fa[x]==x)return x;return fa[x]=find(fa[x]);}
inline bool cmp(const Edge&x,const Edge&y){return x.z<y.z;}
ll kru()
{
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(E+1,E+1+m,cmp);
	vector<Edge>in;
	ll s=0;
	for(int i=1;i<=m;i++)
	{
		int x=find(E[i].x),y=find(E[i].y);
		if(x!=y)fa[x]=y,in.pb(E[i]),s+=E[i].z;
	}
	m=n-1;
	for(int i=1;i<=m;i++)E[i]=in[i-1];
	return s;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>E[i].x>>E[i].y>>E[i].z;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	ll ans=kru();
	for(int j=1;j<=m;j++)e[++mm]=E[j];
	for(int j=1;j<=k;j++)for(int l=1;l<=n;l++)e[++mm]=(Edge){l,n+j,a[j][l]};
	sort(e+1,e+1+mm,cmp);
	for(int i=1;i<(1<<k);i++)
	{
		ll nowans=0;
		for(int j=1;j<=k;j++)if(i&(1<<(j-1)))nowans+=c[j];
		if(nowans>=ans)continue;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=mm;j++)
		{
			if(nowans>=ans)break;
			if(e[j].y>n&&(!(i&(1<<(e[j].y-n-1)))))continue;
			int x=find(e[j].x),y=find(e[j].y);
			if(x!=y)fa[x]=y,nowans+=e[j].z;
		}
		ans=min(ans,nowans);
	}
	cout<<ans;
	return 0;
}

