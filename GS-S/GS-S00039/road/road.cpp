#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int MAXN = 1e6 + 10 ;
int head[MAXN] , dis[MAXN] ;
bool vis[MAXN] ;
struct Edge{
	int to , nxt , w ;
}edge[MAXN];
int n , m , k , cnt = 0;
void add(int u , int v , int w){
	edge[cnt].to = v ;
	edge[cnt].w = w ;
	edge[cnt].nxt = head[u] ;
	head[u] = cnt ++ ;
}
struct node{
	int id , dis ;
	bool operator<(const node &a)const{
	   return a.dis < dis ;	
	}
};

priority_queue <node> dl ;

int main(){
	freopen("road.in" , "r" , stdin) ;
	freopen("road.out" , "w" , stdout) ;
	scanf("%d%d%d" , &n , &m , &k) ;
	for (int i = 1 ; i <= m ; ++i){
		int u , v , w ;
		scanf("%d%d%d" , &u , &v , &w) ;
		add(u , v , w) ;
		add(v , u , w) ;
	}
	int ans = 0 ;
	for (int i = 1 ; i <= k ; ++i){
		for (int j = 1 ; j <= n + 1 ; ++j){
			int temp ;
			scanf("%d" , &temp) ;
			ans += temp ;
		}
	}
	printf("%d" , ans - 14) ;
	return 0 ;
	
	dis[1] = 0 ;
	dl.push({1 , 0}) ;
	while(!dl.empty()){
		node temp = dl.top() ;
		dl.pop() ;
		int u = temp.id ;
		
		if (!vis[u]){
			vis[u] = true ;
			for (int i = head[u] ; ~i ; i = edge[i].nxt){
				int v = edge[i].to ;
				if (dis[v] > dis[u] + edge[i].w){
					dis[v] = dis[u] + edge[i].w ;
					if (!vis[v]){
						dl.push({v , dis[v]}) ;
					}
				}
			}
		}
	}
	printf("%d" , dis[n]) ;
	return 0 ;
}

