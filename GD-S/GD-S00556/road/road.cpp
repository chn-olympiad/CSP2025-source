#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10,M = 1e6+10;
int fa[N];
long long ans = 0;
struct type{
	int u,v,w;
}a[M];
bool cmp(const type &a,const type &b){
	return a.w<b.w;
}
int find(int v){
	if(fa[v] == v) return v;
	return fa[v] = find(v);
}
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++){
		fa[i] = i;
	} 
	for(int i = 1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i = 1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			ans+=a[i].w;
			fa[a[i].u] = fa[a[i].v];
		}
	}
	cout<<ans;
	return 0;
} 
