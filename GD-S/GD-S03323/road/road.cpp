#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N =2e6+10;
struct edge{
	int u,v,w;
}e[N],G[N];
ll ans;
int n,m,k;
int c[114514],f[114514];
bool cmp(edge x , edge y){
	return x.w < y.w;
}
bool cmp1(edge x , edge y){
	return x.w > y.w; 
}
int find(int x){
	if(x != f[x])f[x] = find(f[x]);
	return f[x];
}
void solve1(){
	for(int i = 1 ; i <= m ; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for(int i = 1 ; i <= n ; i++)f[i]=i;
	sort(e+1,e+1+m,cmp);
	for(int i = 1 ; i <= m ; i++){
		int u = find(e[i].u) , v = find(e[i].v); ll w = e[i].w;
		if(u != v){
			ans += w;
			f[u]=v;
		}
	}
	cout << ans;
}
void solve2(){
	for(int i = 1 ; i <= m ; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for(int i = 1 ; i <= n ; i++)f[i]=i;
	sort(e+1,e+1+m,cmp);
	int cnt=0;
	for(int i = 1 ; i <= m ; i++){
		int u = find(e[i].u) , v = find(e[i].v); ll w = e[i].w;
		if(u != v){
			ans += w;
			f[u]=v;
			cnt++;
			G[cnt].u = u , G[cnt].v = v , G[cnt].w = w;
		}
	}
	sort(G+1,G+1+cnt,cmp1);
	int head = 1;
	while(k--){
		ll p;
		cin >> p;
		for(int i = 1 ; i <= n ; i++){
			cin >> c[i]; 
		}
		for(int i = 1 ; i <= n ; i++)
			for(int j = i+1 ; j <= n ; j++){
				ll l = c[i]+c[j]+p;
				if(l < G[head].w){
					ans = ans-G[head].w+l;
					G[head].w=l;
					head++;
				}
			}
	}
	cout << ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	if(k==0){
		solve1();
	}else{
		solve2();
	}
	
	return 0;
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
