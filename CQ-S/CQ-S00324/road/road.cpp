#include <bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
#define PII pair < int , int >
#define x first
#define y second
using namespace std ;
const int N = 1e4 + 15 , M = 1e6 + 5 ; 
int n , m , k , cnt , hd , c[15] , a[15][N] , f[N] , ans = 0 ; 
vector < PII > g[N] ; 
struct edge{ int x , y , z ; }b[M] ; 
vector < edge > hx ; 
int Find(int x){ return f[x] == x ? x : f[x] = Find(f[x]) ; }
pair < int , PII > pq[M + N] ; 
signed main(){
	freopen("road.in" , "r" , stdin) ;
	freopen("road.out" , "w" , stdout) ;
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n >> m >> k ; cnt = m ;  
	for(int i = 1 ; i <= m ; i++){
		int u , v , w ; cin >> u >> v >> w ; b[i] = {u , v , w} ; 
		g[u].push_back({v , w}) ; 
		pq[i] = {w , {u , v}} ; 
	}
	for(int i = 1 ; i <= k ; i++){
		cin >> c[i] ; 
		for(int j = 1 ; j <= n ; j++) cin >> a[i][j] ; 
	}
	for(int i = 1 ; i <= n ; i++) f[i] = i ; 
	sort(pq + 1 , pq + cnt + 1) ; hd = 1 ; 
	while(hd <= cnt){
		auto tmp = pq[hd] ; hd++ ; 
		int w = tmp.x , u = tmp.y.x , v = tmp.y.y ; 
		int X = Find(u) , Y = Find(v) ; 
		if(X == Y) continue ; 
		f[X] = Y ; hx.push_back({u , v , w}) ; ans += w ; 
	}
	for(int S = 1 ; S < (1ll << k) ; S++){
		int sum = 0 ; hd = 1 ; cnt = 0 ; 
		for(int i = 1 ; i <= n + k ; i++) f[i] = i ; 
		for(int i = 1 ; i <= k ; i++) if(S >> i - 1 & 1){
			sum += c[i] ; 
			for(int j = 1 ; j <= n ; j++) pq[++cnt] = {a[i][j] , {i + n , j}} ; 
		}
		for(auto p : hx) pq[++cnt] = {p.z , {p.x , p.y}} ; 
		sort(pq + 1 , pq + cnt + 1) ; 
		while(hd <= cnt){
			auto tmp = pq[hd] ; hd++ ; 
			int w = tmp.x , u = Find(tmp.y.x) , v = Find(tmp.y.y) ; 
			if(u == v) continue ; 
			f[u] = v ; sum += w ; 
			if(sum >= ans) break ; 
		}
		ans = min(sum , ans) ; 
	}
	cout << ans ; 
	return 0 ;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

那么不采取原本的道路，当且仅当w_i<=c_j+a_j_i+a_j_k 
关键是你修改好这个玩意，你就不用花费c_j的费用了 
不对，2^10 
这不1e9了吗？
那他要不要跟城市建边？这玩意得记啊
找到一个花费更优，那就有必要建图 
 

k只有10？？？ 

最小生成树 


考试就剩16分钟了，打个蛋啊
好吧，只有15分钟了
蒟蒻一个，最多228分，最少8分
让我想想怎么进《迷惑行为大赏》

完了，忘了星铁UID了。

AFO再见，已经1145141919810岁了 

我们老师不会闲着没事看我代码吧。

我是最差的OIer

听说有人考场上火车头写了100多行？

代码写多了是不是还会不读我程序？

可惜没带零食

我没带零食啊！！！！！！！！！1！！！！
 
右边的男生上了6次厕所，或者更多？ 

左边的女生疯狂和coffee 

我的电解制水两口就喝没了，口干的都可以去厕所补充水分了 

星铁数值膨胀太严重了，有点想退坑

监考员是我们老师，我生怕被他看见在写游记

要结束了 
*/

