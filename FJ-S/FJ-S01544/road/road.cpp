#include<bits/stdc++.h>
typedef long long ll;
const int N=1e4+5,M=1e6+5;
using namespace std;
struct edge{
	int u,v;
	ll w;
	bool operator <(const edge b)const{
		return w<b.w ;
	}
}e[M+13*N];
int n,m,k,cnt;
ll c[15],g[15][N]; 
int fa[N];
ll ans;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void join(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u >>e[i].v >>e[i].w ;
	}
	cnt=m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int p;
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
			if(g[i][j]==0) p=j;
		}
		for(int j=1;j<=n;j++){
			e[++cnt].u =p,e[cnt].v =j,e[cnt].w =g[i][j];
		}
	}
	sort(e+1,e+cnt+1);
	for(int i=1;i<=m;i++){
		if(find(e[i].u )==find(e[i].v )){
			continue;
		}
		ans+=e[i].w ;
		join(e[i].u ,e[i].v );
	}
	cout<<ans;
}
// 感觉要四掉了 
//t1原本想了一个做法，后面发现有问题
//只能n^3暴力dp
//15:51 想到了 t2 的一个做法，开打 
//16:23 发现这个做法是错的 要气死了
//只能拿白送的40分了
// 
 
