#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define int long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
inline void read(int& x){
	x=0;
	int f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^'0');
		ch=getchar();
	}
	x*=f;
}
const int N=1e4+20;
struct edge{
	int u,v,w;
	bool operator<(const edge& rhs)const{
		return w<rhs.w;
	}
};
vector<edge> g,gg;
int c[11],a[11][N];
int fa[N],rak[N];
void pre(int n){
	for(int i=1;i<=n;i++)fa[i]=i,rak[i]=1;
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(rak[x]<rak[y])fa[x]=y;
	else fa[y]=x,rak[x]+=(rak[x]==rak[y]);
}
int n,m,k;
int kls(){
	int cnt=0;
	stable_sort(g.begin(),g.end());
	pre(n+k);
	for(edge i:g){
		if(find(i.u)==find(i.v))continue;
		merge(i.u,i.v);
		cnt+=i.w;
	}
	return cnt;
}
bool cmp(const int& lhs,const int& rhs){
	return c[lhs]<c[rhs];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		read(u),read(v),read(w);
		g.push_back({u,v,w});
	}
	gg=g;
	bool f=1;
	for(int i=1;i<=k;i++){
		read(c[i]); 
		if(c[i])f=0;
		for(int j=1;j<=n;j++)read(a[i][j]);
	}
	if(f){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++)g.push_back({n+i,j,a[i][j]});
		}
		printf("%lld",kls());
		return 0;
	}
	int res=kls();
	for(int mask=0;mask<(1<<k);mask++){
		g=gg;
		int cnt=0;
		for(int i=0;i<k;i++){
			if((mask>>i)&1){
				cnt+=c[i+1];
				for(int j=1;j<=n;j++){
					g.push_back({n+i+1,j,a[i+1][j]});
				}
			}
		}
		res=min(res,kls()+cnt);
	}
	printf("%lld",res);
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
