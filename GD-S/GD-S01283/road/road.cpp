#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
struct node{
	int u,v,w;
}e[N];
ll n,m,k;
ll fa[N];
ll ans,cnt;
ll c[N];
ll a[15][N];
ll find(ll x){
	if(x!=fa[x]) return fa[x]=find(fa[x]);
	return x;
}
bool cmp(node a,node b){
	return a.w<=b.w;
}
void kruskal(){
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		ll u=find(e[i].u);
		ll v=find(e[i].v);
		if(u==v){
			continue;
		}
		ans+=e[i].w;
		fa[v]=u;
		cnt++;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	kruskal();
	cout<<ans;
	return 0;
} 
