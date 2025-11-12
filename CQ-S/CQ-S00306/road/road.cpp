#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x = 0 , f = 1;
	char ch = getchar();
	while(!('0' <= ch && ch <= '9')) {
		if(ch == '-')
			f = -f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int N = 1e4 + 5;
const int M = 1e6 + 5;

struct node{
	int u , v , w;
	node(int a = 0 , int b = 0 , int c = 0) : u(a) , v(b) , w(c) {}
	bool operator < (node b) const {
		return w < b.w;
	}
}rd[M];
int fa[N];
int cside[15][N];
int c[15];
int cost = 0;

int find(int u) {
	if(u == fa[u])
		return u;
	return fa[u] = find(fa[u]);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n = read() , m = read() , k = read();
	for(int i = 1 ; i < N ; i++)
		fa[i] = i;
	for(int i = 1 ; i <= m ; i++) {
		int u = read() , v = read() , w = read();
		rd[i] = node(u , v , w);
	}
	sort(rd+1 , rd+1+m);
	for(int i = 1 ; i <= k ; i++) {
		c[i] = read();
		for(int j = 1 ; j <= n ; j++)
			cside[i][j] = read();
	}
	//temp
	for(int i = 1 ; i <= m ; i++) {
		int u = rd[i].u , v = rd[i].v , w = rd[i].w;
		int fu = find(u) , fv = find(v);
		if(fu == fv) continue;
		fa[fu] = fv;
		cost += w;
	}
	cout << cost;

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

