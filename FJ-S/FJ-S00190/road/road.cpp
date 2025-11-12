#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int maxn = 1e4 + 5;
const int maxm = 1e6 + 2e5;

struct node{
	int u, v, w;
};

int n, m, k, cnt, ans1, ans2;
int c[maxn], fa[maxn];
vector<node> g;

void read(int &x){
	x = 0;
	int f = 1;
	char c = getchar();
	while (!isdigit(c)){
		if (c == '-'){
			f = -1;
		}
		c = getchar();
	}	
	while (isdigit(c)){
		x = x * 10 + c - 48;
		c = getchar();
	}
	x *= f;
	return ;
}

int find(int x){
	return x == fa[x]? x : fa[x] = find(fa[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	fa[x] = y;
}

bool cmp(node a, node b){
	return a.w < b.w;
} 

void kru(){
	sort(g.begin(), g.end(), cmp);
	for (auto edge : g){
		if (find(edge.u) == find(edge.v)){
			continue;
		}
		cnt++;
		ans1 += edge.w;
//		cout << edge.u<<" "<<edge.v<<" "<<edge.w<<"\n";
		merge(edge.u, edge.v);
		if (cnt == n - 1){
			break;
		}
	}
	return ;
}

void kru2(){
	sort(g.begin(), g.end(), cmp);
	for (auto edge : g){
		if (find(edge.u) == find(edge.v)){
			continue;
		}
		cnt++;
		ans2 += edge.w;
//		cout << edge.u<<" "<<edge.v<<" "<<edge.w<<"\n";
		merge(edge.u, edge.v);
		if (cnt == n){
			break;
		}
	}
	return ;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	iota(fa + 1, fa + n + 1, 1); 
	for (int i = 1; i <= m; ++i){
		int u, v, w;
		read(u), read(v), read(w);
		g.push_back({u, v, w});
		g.push_back({v, u, w});
	}
//	cout << "=-=====\n";
	kru();
//	cout << "=-=====\n";
	for (int i = 1; i <= k; ++i){
		read(c[i]);	
		for (int j = 1; j <= n; ++j){
			int w;
			read(w);
			g.push_back({n + 2, j, w + c[i]});
			g.push_back({j, n + 2, w + c[i]});
		}
	} 
//	cout <<"=======\n";
	cnt = 0;
	iota(fa + 1, fa + n + 1, 1); 
	kru2();
	cout << min(ans1, ans2);
	return 0;
}
/*
先形式化题意：
给定一个n个点m条边的图，每条边链接u,v边权w，再给定k个点每个点与原图上的每个点都有连边，有边权，且必须选择完点才能选
现在可以选择一些点和边，使图联通且点权和+边权和最小
发现边权，点权都非常大，很可能要高精度，像之前的一道拓扑排序+高精度的图论题
貌似可以用最小生成树来做
直接kru，来不及调了
希望能捞点分，不然得AFO了



18中电脑还是那么难用，无论电脑，键盘，鼠标 
*/
