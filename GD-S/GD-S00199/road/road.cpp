#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e4+6;
ll n,m,k;
bool A=1;
struct edge{
	ll v,w;
};
struct node{
	ll u,v,w,w2=0,dg=0;
}e[N*100];
bool operator<(edge A,edge B){
	return A.w>B.w;
}
bool cmp(node A,node B){
	return A.w<B.w;
}
vector<edge> G[N];
ll c[16],a[16][N],fa[N];
ll ans=0,cnt=0;
ll get(ll x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=get(fa[x]);
}
bool vis[16];
void kru(ll u,ll v,ll w,ll w2,ll dg){
	u=get(fa[u]);
	v=get(fa[v]);
	if(u==v){
		return ;
	}
	cnt++;
	if(dg==0)ans+=w;
	else{
		if(vis[dg]){
			ans+=w2;
		}
		else{
			ans+=w;
			vis[dg]=1;
		}
	}
	fa[u]=v;
	return ;
}

void work1(){
	for(ll i = 1;i <= n;++i){
		fa[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	for(ll i = 1;i <= m;++i){
	//	cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
		kru(e[i].u,e[i].v,e[i].w,e[i].w2,e[i].dg);
	}
	cout << ans << endl;
	return ;
}
void work2(){
	cout << 0 <<endl;
	return ;
}
void sub3(){
	
	for(ll i = 1;i <= k;++i){
		for(ll j = 1;j <= n;++j){
			for(ll d = j+1;d <= n;++d){
				G[j].push_back({d,c[i]+a[i][j]+a[i][d]});
				G[d].push_back({j,c[i]+a[i][j]+a[i][d]});
				e[++m].u=d;	
				e[m].v=j;
				e[m].w=c[i]+a[i][j]+a[i][d];
				e[m].w2=a[i][j]+a[i][d];
				e[m].dg=i;
			}
		}
	}
	work1();
	
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i = 1;i <= m;++i){
		ll u,v,w;cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
	}
	for(ll i = 1;i <= k;++i){
		cin>>c[i];
		for(ll j = 1;j <= n;++j){
			cin>>a[i][j];
			if(a[i][j]!=0||c[i]!=0){
				A=0;
			}
		}
	}
	if(k==0){
		work1();
	}
	else if(A==1){
		work2();
	}
	else{
		sub3(); 
	}
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 4
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

