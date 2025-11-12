#include <bits/stdc++.h>
using namespace std;
int n, m, k, u, v, w, c[12], a[12][1000002], ans, cnt, f[1000002];
struct edge{
	int u, v, w;
}e[2000002];
int find(int x){
	if(x==f[x]){
		return x;
	}
	f[x]=find(f[x]);
	return f[x];
}
bool cmp(edge x, edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++){
		cin>>u>>v>>w;
		e[i]={u, v, w};
	}
	for(int i = 1; i <= n; i++){
		f[i]=i;
	}
	for(int i = 1; i <= k; i++){
		cin>>c[i];
		bool f=0;
		for(int j = 1; j <= n; j++){
			cin>>a[i][j];
		}
	}
	for(int i = 1; i <= k; i++){
		int man=0;
		for(int j = 1; j <= n; j++){
			if(!a[i][j]){
				man=j;
				break;
			}
		}
		for(int j = 1; j <= n; j++){
			if(j==man){
				continue;
			}
			e[++m]={man, j, a[i][j]};
		}
	}
	sort(e+1, e+m+1, cmp);
	for(int i = 1; i <= m; i++){
		auto [u, v, w]=e[i];
		int fu=find(u), fv=find(v);
		if(fu!=fv){
			cnt++;
			ans+=w;
			f[fu]=fv;
		}
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans;
	
}