#include <bits/stdc++.h>
#define pa pair <int, pair <int, int> >
using namespace std;
//真的服了，写了一个半小时最后只有32分 
inline int read(){
	int cnt = 0, f = 1;
	char h = getchar();
	while(h < '0' || h > '9'){
		if(h == '-')f = -f;
		h = getchar();
	}
	while(h >= '0' && h <= '9'){
		cnt = (cnt << 3) + (cnt << 1) + (h ^ 48);
		h = getchar();
	}
	return cnt * f;
}

inline void write(int x){
	if(x < 0){
		putchar('-');
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x % 10 + '0');
}

const int N = 1e6 + 100, M = 1e4 + 100;
int n, m, k, ans = INT_MAX;
pa mp[N];
//struct node{
//	int u, v, w;
//	const bool operator < (const node &i, const node &j){
//		return i.w < j.w;
//	}
//};
//重载运算符不会写啦！！！ 
int c[15];
int a[15][M];
bool flag[15];//0不改造 
int f[N];

int find(int x){
	if(x == f[x])return x;
	else return f[x] = find(f[x]);
}

int Kruskal(){
	priority_queue <pa, vector <pa>, greater <pa> > q;
	memset(f, 0, sizeof(f));
	int cnt = 0;
	int mn = 0;
	for(int i = 1; i <= k; i++){
		if(flag[i] == 1){
			mn += c[i];
			for(int j = 1; j <= n; j++){
				q.push({a[i][j], {n + i, j}});
			}
			cnt++;
		}
	}
	for(int i = 1; i <= m; i++){
		q.push(mp[i]);
	}
	int nn = n + cnt - 1;
	for(int i = 1; i <= nn + 1; i++)f[i] = i;
	int sum = 0;
	while(sum < nn){
		pa thi = q.top();q.pop();
		int u = thi.second.first, v = thi.second.second, w = thi.first;
		int fu = find(u), fv = find(v);
		if(fu != fv){
			sum++;
			f[fu] = fv;
			mn += w;
		}
	}
	return mn;
}

void dfs(int x){//求那些乡村要改造
	if(x == k + 1){
		ans = min(ans, Kruskal());
		return;
	}
	dfs(x + 1);
	flag[x] = 1;
	dfs(x + 1);
	flag[x] = 0;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++){
		int x = read(), y = read(), w = read();
		mp[i] = {w, {x, y}};
	}
	for(int i = 1; i <= k; i++){
		c[i] = read();
		for(int j = 1; j <= n; j++){
			a[i][j] = read();
		}
	}
	dfs(1);
	write(ans);
	return 0;
}

