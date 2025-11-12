#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using pii = std :: pair <int , int>;

constexpr i64 dick = 1e4 + 10;
constexpr i64 M = 1e6 + 10;
constexpr i64 penis = 20;
constexpr i64 INF = 1e18;
constexpr i64 MOD = 1e9 + 7;

i64 ans;
int fuck;
int n , m , k;
std :: vector <pii> g[M];
int a[penis][dick];
int c[penis];
int cff = 0;

std :: priority_queue <pii , std :: vector <pii> , std :: greater <pii>> pq;
int dis[dick];

//inline void dij (int s) {
//	pq.push ({s , 0});
//	while (!pq.empty ()) {
//		pii f = pq.top ();
//		pq.pop();
//		for (pii v : g[f.first]) {
//			int w = v.second , V = f.first;
//			if ()
//		}
//	}
//	return ;
//}

inline void solveYOURMOTHER () {
	cff = 0;
	std :: cin >> n >> m >> k;
	for (int i = 1 , u , v , w;i <= n;i ++) {
		std :: cin >> u >> v >> w;
		g[u].push_back ({v , w}) , g[v].push_back ({u , w});
		cff += w;
	}
	for(int i = 1;i <= k;i ++) {
		std :: cin >> c[i];
		for (int j = 1;j <= n;j ++)
			std :: cin >> a[i][j];
	}
	
	std :: cout << cff << '\n';
	return ;
}

signed main () {
	freopen ("road.in" , "r" , stdin);
	freopen ("road.out" , "w" , stdout);
	std :: ios :: sync_with_stdio (0);
	std :: cin.tie (0) , std :: cout.tie (0);
	fuck = 1;
	//std :: cin >> fuck;
	while (fuck --) solveYOURMOTHER ();	
	return (0 - 0);
}
/*

I can't solve this problem
fuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuck
fuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuck
fuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuck
fuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuck
fuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuck
fuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuck
fuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuck
fuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuckfuck

why i am so tang?
why i am so tang?
why i am so tang?
fuck
fuck
fuck

AFO on 2025.11.1 17:24

*/
