#include<bits/stdc++.h>
using namespace std;

const int maxm = 2e6+10,maxn = 1e4+20;
int n,m,k,cnt;
long long ans;
struct str{
	int u,v,c;
}road[maxm],road_;
int fa[maxn];

int find(int x){
	return fa[x] == x?x:fa[x] = find(fa[x]);
}
bool cmp(str x,str y){
	return x.c < y.c;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1,u,v,w;i <= m;i ++){
		cin >> road_.u >> road_.v >> road_.c;
		road[++cnt] = road_;
	}
	
	for(int u = n+1;u <= n+k;u ++){
		cin >> road_.c;
		for(int v = 1;v <= n;v ++){
			cin >> road_.c;
			road_.u = u,road_.v = v;
			road[++cnt] = road_;
		}
	}
	
	sort(road+1,road+1+cnt,cmp);
	for(int i = 1;i <= n+k;i ++) fa[i] = i;
	
	for(int i = 1,u,v;i <= cnt;i ++){
		u = road[i].u,v = road[i].v;
		if(find(u) == find(v)) continue;
		fa[find(u)] = find(v);
		ans += road[i].c;
	}
	
	cout << ans;
	return 0;
} 
/*
 4 4 1
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4

*/
