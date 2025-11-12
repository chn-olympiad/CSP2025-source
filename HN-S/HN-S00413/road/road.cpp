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
int n,m,k,c[15],a[15][10005];
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
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	// scanf("%d%d%d",&n,&m,&k);
	n=read(),m=read(),k=read();
	// n=10000,m=1000000,k=10;
	// srand(time(0));
	for(int i=1;i<=m;i++){
		int a,b,c;
		// scanf("%d%d%d",&a,&b,&c);
		a=read(),b=read(),c=read();
		// a=(i%n?i%n:n),b=i%n+1,c=rand();
		E[i]={a,b,c};
	}
	bool check=1;
	for(int j=1;j<=k;j++){
		// scanf("%d",&c[j]);
		c[j]=read();
		// c[j]=rand()/2*rand();
		check&=!c[j];
		bool fl=0;
		for(int i=1;i<=n;i++){
			// scanf("%d",&a[j][i]);
			a[j][i]=read();
			// a[j][i]=rand()/2*rand();
			fl|=!a[j][i];
		}
		check&=fl;
	}
	// auto ST=clock();
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++)
			v[j][i]=(pip){a[j][i],{j+n,i}};
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
	for(int _=1;_<(1<<k);_++){
		if(check&&_!=(1<<k)-1){_=(1<<k)-1-1;continue;}
		LL S=0;int U=n;
		priority_queue<pip,vector<pip>,greater<pip> >q;
		q.push({v[k+1][1].fi,{k+1,1}});//[w,[line,pos]]
		for(int j=0;j<k;j++)
			if((_>>j)&1){
				S+=c[j+1],U+=n;
				q.push({v[j+1][1].fi,{j+1,1}});
			}
		T.Init(n+k);
		for(int __=1;__<=U;__++){
			auto now=q.top();q.pop();
			int i=now.se.fi,p=now.se.se;
			int aa=T.Find(v[i][p].se.fi),bb=T.Find(v[i][p].se.se);
			if(aa!=bb){
				T.Union(aa,bb);
				S+=v[i][p].fi;
			}
			p++;
			if(p<=n)q.push({v[i][p].fi,{i,p}});
		}
		ans=min(ans,S);
	}
	cout<<ans;
	// auto EN=clock();
	// cerr<<(EN-ST)*1.0/CLOCKS_PER_SEC<<endl;

	return 0;
}