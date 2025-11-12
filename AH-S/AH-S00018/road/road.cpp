#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define MP make_pair
typedef long long ll;
typedef unsigned long long ull;
template <class Miaowu>
inline void in(Miaowu &x){
	char c;x=0;bool f=0;
	for(c=getchar();c<'0'||c>'9';c=getchar())f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=2e4+5;
const int M=1e6+5;
ll ans;
int n,m,K,dsu[N],cst[15];
pii c[15][N];
struct Edge{int u,v,w;}e[M],ee[N],e1[N];
inline int Find(int u){return u==dsu[u]?u:dsu[u]=Find(dsu[u]);}
inline void solve(int rt,int mm,ll sm){
	if(rt>K)return;
	solve(rt+1,mm,sm);
	vector<Edge>vc(mm+1);
	for(int i=1;i<=mm;i++)vc[i]=ee[i];
	int tot=0,ii=1,jj=1;
	while(ii<=mm&&jj<=n){
		if(ee[ii].w<c[rt][jj].first)e1[++tot]=ee[ii++];
		else e1[++tot]=Edge{n+rt,c[rt][jj].second,c[rt][jj].first},jj++;
	}
	while(ii<=mm)e1[++tot]=ee[ii++];
	while(jj<=n)e1[++tot]=Edge{n+rt,c[rt][jj].second,c[rt][jj].first},jj++;
	for(int i=1;i<=n+rt;i++)dsu[i]=i;
	sm+=cst[rt];ll qwq=sm;int tt=0;
	for(int i=1;i<=tot;i++){
		int u=e1[i].u,v=e1[i].v,fu=Find(u),fv=Find(v);
		if(Find(fu)!=Find(fv))qwq+=e1[i].w,dsu[fu]=fv,ee[++tt]=e1[i];
	}
	ans=min(ans,qwq);
	solve(rt+1,mm+1,sm);
	for(int i=1;i<=mm;i++)ee[i]=vc[i];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	in(n),in(m),in(K);
	for(int i=1,u,v,w;i<=m;i++)in(u),in(v),in(w),e[i]=Edge{u,v,w};
	stable_sort(e+1,e+m+1,[](Edge _1,Edge _2){return _1.w<_2.w;});
	for(int i=1;i<=n;i++)dsu[i]=i;
	for(int i=1,tt=0;i<=m;i++){
		int u=e[i].u,v=e[i].v,fu=Find(u),fv=Find(v);
		if(fu!=fv)dsu[fu]=fv,ans+=e[i].w,ee[++tt]=e[i];
	}
	for(int i=1;i<=K;i++){
		in(cst[i]);
		for(int j=1;j<=n;j++)in(c[i][j].first),c[i][j].second=j;
		stable_sort(c[i]+1,c[i]+n+1);
	}
	solve(1,n-1,0);
	cout<<ans<<endl;
	return 0;
}