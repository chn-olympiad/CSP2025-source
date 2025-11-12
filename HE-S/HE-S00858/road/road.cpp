#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct City{
	int c;
	vector<int> w;
};
//我不是图灵 
//这个题应该是dijstra跑最短路，我曾经认为（实际上也是）随便切各种最短路。于是半年没复习^_^我是傻逼。。。 
//我这种蒟蒻下次一定好好复习 
//又给万恶的系系欸夫交学费了
//但是今天秦皇岛的晚霞好漂亮啊
//我这次也就比不爆零强一点^_^
//应该是还没有上次考的高^_^^_^^_^^_^^_^^_^^_^^_^^_^
//^_^^_^^_^^_^^_^^_^^_^^_^^_^^_^ 
//我不是图灵 
//我不是图灵 
//我不是图灵 
//我不是图灵 
//我不是图灵 
//我不是图灵 
//我不是图灵
//我不是图灵 
//蒟蒻++ 
//蒟蒻++
//蒟蒻++
//蒟蒻++
//蒟蒻++
//蒟蒻++
//蒟蒻++
//蒟蒻++
//蒟蒻++
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<vector<pii> > r(m + 1);
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		r[u].push_back(make_pair(v, w));
		r[v].push_back(make_pair(u, w));
	}
	vector<City> city(k);
	for(int i = 0; i < k; i++){
		int ci;
		scanf("%d", &ci);
		city[i].c = ci;
		city[i].w.resize(n);
		for(int j = 0; j < n; j++){
			scanf("%d", &city[i].w[j]);
		}
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
