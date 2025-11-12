#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef pair<int , int> ull;
priority_queue <ull , vector<ull> , greater<ull> > p;
int cnt , h[N] , flag[N] , dist[N];
int n , m , k;
struct node{
	int u , v , w;
}e[N];
void add(int u , int v , int w){
	e[++ cnt].u = v;
	e[cnt].w = w;
	e[cnt].v = h[u];
	h[u] = cnt;
}
void dij(int x){
	p.push({0 , x});
	flag[x] = 1;
	memset(dist , 0x3f , sizeof dist);
	for(int i = 1 ; i <= m ; i ++){
		auto t = p.top();
		p.pop();
		int d = t.first , no = t.second;
		if(flag[no] == 1) continue;
		flag[no] = 1;
		for(int j = e[i].u ; j ; j = e[i].v){
			int t = e[i].u;
			if(dist[t] > dist[no] + e[t].w){
				dist[t] = dist[no] + e[t].w;
				if(flag[no] == 0){
					flag[no] = 1;
					p.push({dist[t] , t});
				}
			}
		}
	} 
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);	
	scanf("%d%d%d" , &n , &m , &k);
	if(k > 0) return 0;
	for(int i = 1 ; i <= m ; i ++){
		int x , y , z;
		cin >> x >> y >> z;
		add(x , y , z);
	}
	dij(1);	
	for(int i = 1 ; i <= n ; i ++){
		cnt += dist[i];
	}
	printf("%d" , cnt);
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
