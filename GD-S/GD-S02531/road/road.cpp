#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
ll read(){
	ll Num=0,f=1;
	char c = getchar();
	while(c < '0'||c > '9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		Num=(Num<<1)+(Num<<3)+(c^48);
		c=getchar();
	}
	return Num*f;
}
constexpr int M=1e6+1e5+5,N=1e4+15;
struct Node{
	int u,v;
	ll w;
	bool operator<(const Node& other)const{
		return w<other.w;
	}
};
vec<Node> Edge;
int fa[N],n,m,k;
int find(int x){
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
void Kruskal(){
	ll sum=0;int cnt=0;
	stable_sort(Edge.begin(),Edge.end());
	for(auto _ : Edge){
		int u=_.u,v=_.v; ll w=_.w;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		sum+=w;
		fa[u]=v;
		++cnt;
		if(cnt==n-1)break;
	}
	printf("%lld",sum);
}
void SolVe(){
	n=read(),m=read(),k=read();
	for(int i=1,u,v;i<=m;++i){
		ll w; u=read(),v=read(),w=read();
		Edge.push_back({u,v,w});
		Edge.push_back({v,u,w});
	}
	if(!k){
		for(int i=1;i<=n;++i)fa[i]=i;
		Kruskal();
		return;
	}
	for(int i=1;i<=k;++i){
		ll c=read(); int id=i+n;
		for(int j=1,v;j<=n;++j){
			ll l=read();
			Edge.push_back({id,j,c+l});
			Edge.push_back({j,id,c+l});
		}
	}
	m=2*m+2*k*n;
	Edge.reserve(m+5);
	for(int i=1;i<=n;++i)fa[i]=i;
	Kruskal();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int T=1;
    //T=read();
    while(T--) SolVe();
	return 0;
}
