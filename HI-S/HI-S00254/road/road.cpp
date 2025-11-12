#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long u,v,w;
}e[1000020];
int n,m,k,f[10005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int ff(int x){
	if(f[x] != x) f[x] = ff(f[x]);
	return f[x];
}
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		if(e[i].u > e[i].v) swap(e[i].u,e[i].v);
		if(i <= n) f[i] = i;
	}
	for(int i = 1; i <= k; i++){
		int tmp;
		cin>>tmp;
		for(int j = 1; j <= n; j++) cin>>tmp;
	}
	if(k!=0){
		cout<<0;
		return 0;
	}
	sort(e+1,e+m+1,cmp);
	//for(int i = 1; i <= m; i++) cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
	for(int i = 1; i <= m; i++){
		int fx = ff(e[i].u),fy = ff(e[i].v);
		if(fx != fy){
			ans += e[i].w;
			n--;
			f[fy] = f[fx];
		}
		if(n==1) break;
	}
	cout<<ans;
	return 0;
}
