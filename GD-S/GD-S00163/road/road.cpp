#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;
using ll = long long;
constexpr int N = 2e4 + 10, M = 3e7 + 10, K = 12;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,k,len,cnt;
ll c[N],a[K][N],fa[N];
ll ans;
struct node{
	int u,v;
	ll w;
}g[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
vector<pair<int,ll>> e[N];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if (u^v) fa[v]=u;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for (int i=1,u,v,w;i<=m;i++){
		u=read(),v=read(),w=read();
		e[u].pb(v,w),e[v].pb(u,w);
	}
	for (int j=1;j<=k;j++){
		c[j]=read();
		for (int i=1;i<=n;i++){
			a[j][i]=read();
		}
	}
	for (int i=1;i<=n;i++){
		fa[i]=i;
		for (int j=1;j<=k;j++){
			for (int l=1;l<=n;l++){
				e[i].pb(l,a[j][i]+c[j]+a[j][l]);
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (auto it:e[i]) 
			g[++len]={i,it.first,it.second};
	}
	
	sort(g+1,g+len+1,cmp);
	for (int i=1;i<=len;i++){
		ll u=g[i].u,v=g[i].v,w=g[i].w;
		if (find(u)^find(v)){
			merge(u,v);
			ans+=w;
			cnt++;
			if (cnt==n-1) break;
		}
	}
	cout << ans;
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
