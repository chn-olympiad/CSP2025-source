#include<bits/stdc++.h>
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c-'0'),c=getchar();
	return x;
}
#define eps 1e-6
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
#define fi first
#define se second
#define MOD 998244353
#define MAXN 1000005
int n,m,k,c[15];
typedef pair<int,pii> pip;
pip v[15][10005];int tot;
struct edge{int u,v,w;}E[MAXN];
bool cmp(edge a,edge b){return a.w<b.w;}
LL ans;
struct UnionFindTree{
	int f[20005],siz[20005];
	void Init(int n){for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;}
	inline int Find(int x){return f[x]==x?x:f[x]=Find(f[x]);}
	inline void Union(int a,int b){
		if(siz[a]>siz[b])
			f[b]=a,siz[a]+=siz[b];
		else f[a]=b,siz[b]+=siz[a];
	}
}T;
bool bl[15];
signed main(){
	// auto ST=clock();
	freopen("road4.in","r",stdin);
	// freopen("road.out","w",stdout);
	// scanf("%d%d%d",&n,&m,&k);
	n=read(),m=read(),k=read();
	// n=10000,m=1000000,k=10;
	// srand(time(0));
	for(int i=1;i<=m;i++){
		int a,b,c;
		//scanf("%d%d%d",&a,&b,&c);
		a=read(),b=read(),c=read();
		// a=(i%n?i%n:n),b=i%n+1,c=rand();
		E[i]={a,b,c};
	}
	for(int j=1;j<=k;j++){
		// scanf("%d",&c[j]);
		c[j]=read();
		// c[j]=rand()/2*rand();
		for(int i=1;i<=n;i++){
			// int x;scanf("%d",&x);
			int x=read();
			// int x=rand()/2*rand();
			v[j][i]=(pip){x,{j+n,i}};
		}
		sort(v[j]+1,v[j]+n+1);
	}
	sort(E+1,E+m+1,cmp);
	T.Init(n);
	for(int i=1;i<=m;i++){
		int a=T.Find(E[i].u),b=T.Find(E[i].v);
		if(a!=b){
			T.Union(a,b),ans+=E[i].w;
			v[k+1][++tot]=(pip){E[i].w,{E[i].u,E[i].v}};
		}
	}
	assert(tot==n-1);
	v[k+1][n]=(pip){inf,{1,1}};
	// for(int _=1;_<(1<<k);_++)
	{
		int _=(1<<k)-1;
		LL S=0;int U=n;
		set<pip>q; q.insert({v[k+1][1].fi,{k+1,1}});//[w,[line,pos]]
		for(int j=0;j<k;j++)
			if((_>>j)&1){
				S+=c[j+1],U+=n;
				q.insert({v[j+1][1].fi,{j+1,1}});
			}
		T.Init(n+k);
		for(int __=1;__<=U;__++){
			auto now=*q.begin();q.erase(q.begin());
			int i=now.se.fi,p=now.se.se;
			int a=v[i][p].se.fi,b=v[i][p].se.se;
			int aa=T.Find(a),bb=T.Find(b);
			if(aa!=bb){
				T.Union(aa,bb);
				S+=v[i][p].fi;
				if(a>n){
					if(!bl[a-n])bl[a-n]=1;
					else bl[a-n]=-2;
				}
			}
			p++;
			if(p<=n)q.insert({v[i][p].fi,{i,p}});
		}
		for(int i=1;i<=k;i++)
			if(T.Find(n+i)==n+i||bl[i]==-2)
				S-=c[i];
		ans=min(ans,S);
	}
	cout<<ans;
	// auto EN=clock();
	// cerr<<(EN-ST)*1.0/CLOCKS_PER_SEC<<endl;

	return 0;
}