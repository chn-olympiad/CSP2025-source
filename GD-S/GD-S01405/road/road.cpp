#include <bits/stdc++.h>
#define ll long long
#define bit bit_fjdskajlkfdsja
using namespace std;
namespace lch{
bool bit(int s,int i){ return (s>>(i-1))&1; }
inline int read(){
	int x=0; char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=x*10+(c^48);
	return x;
}
const int N=1e4+20;
int n,m,k;
vector<array<int,3>> tmp,E;
struct dsu_t{
	int fa[N];
	void init(){ for(int i=1;i<N;i++) fa[i]=i; }
	int find(int x){ while(x!=fa[x]) x=fa[x]=fa[fa[x]]; return x; }
	void merge(int x,int y){ fa[find(x)]=find(y); }
	bool same(int x,int y){ return find(x)==find(y); }
}dsu;
int self[11],val[11][N];
int main(){
	n=read(); m=read(); k=read();
	tmp.resize(m);
	for(auto&[w,u,v]:tmp) u=read(),v=read(),w=read();
	sort(tmp.begin(),tmp.end());
	dsu.init();
	for(auto [w,u,v]:tmp) if(!dsu.same(u,v)) E.push_back({w,u,v}),dsu.merge(u,v);
	for(int i=1;i<=k;i++){
		self[i]=read();
		for(int j=1;j<=n;j++){
			val[i][j]=read();
			E.push_back({val[i][j],n+i,j});
		}
	}
	sort(E.begin(),E.end());
	ll fin=1e18;
	for(int s=0;s<(1<<k);s++){
		ll tot=0;
		for(int i=1;i<=k;i++) if(bit(s,i)) tot+=self[i];
		dsu.init();
		for(auto [w,u,v]:E) if((u<=n||bit(s,u-n))&&!dsu.same(u,v)){
			tot+=w; dsu.merge(u,v);
		}
		fin=min(fin,tot);
	}
	printf("%lld\n",fin);
	return 0;
}
}
int main(){
#ifndef LCH
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	auto st=clock();
	int r=lch::main();
	cerr<<"Time: "<<clock()-st<<"ms\n";
	return r;
}

