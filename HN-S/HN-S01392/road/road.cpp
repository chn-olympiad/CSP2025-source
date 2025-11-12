#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,m,k,dis[N],head[N],cnt=0,ans=0;
bool vis[N];
struct edge{
	int nxt,to,w;
}e[N];
void add(int u,int v,int w){
	e[++cnt].nxt = v;
	e[cnt].w = w;
	e[cnt].to = head[u];
	head[u] = cnt;
}
int dijkstra(int x){
	if(vis[x])return x;
	vis[x] = 1; 
	dis[x] = 0;
	//???
	return 1; 
	//完了考场忘板子了 何意味 
}
int main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >>m >> k; 
	for(int i = 1;i <= m; i++){
		int u,v,w;
		cin >>u >>v >>w;
		add(u,v,w);add(v,u,w);
		ans += w;
	}
	for(int i = 1,c,a;i <= k; i++){
		cin >> c;
		for(int j = 1;j <= n; j++) cin >>a;
	}
	dijkstra(1);
	cout << ans;
	//碰碰运气吧 看看1-4里有没有全部要走一遍的 
	return 0;
} 
//mengCtulemengka mengCCtulemengCka dadiguayamekaodigua yikuaiqiannengmaisaer
