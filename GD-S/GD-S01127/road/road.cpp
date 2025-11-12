#include <iostream>
#include <algorithm>
using namespace std;
inline void read(int &x){
	x = 0;
	int sign = 1;
	char c = getchar();
	while (!isdigit(c)){
		if(c == '-') sign = -1;
		c = getchar();
	} 
	while (isdigit(c)){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= sign;
}
struct Node{
	int a, b, c;
	inline bool operator< (const Node &w) const{	
		return c < w.c;
	}
};
Node e[1100010], ne[120010];
int p[20010], c[12];
int n, m, k;
int find(int x){
	if(p[x] == x) return x;
	return p[x] = find(p[x]);
}
int cnt = 0;
long long res = 1e18;
inline void work(int id){
	int i;
	int u, v, w, fu, fv;
	for (i = 1; i <= n + k; i ++ ) p[i] = i;
	long long now = 0;
	for (i = 1; i <= k; i ++ )
		if(id >> (i - 1) & 1) now += c[i];
	for (i = 1; i <= cnt; i ++ ){
		u = ne[i].a, v = ne[i].b, w = ne[i].c;
		fu = find(u), fv = find(v);
		if(u > n && !(id >> (u - n - 1) & 1)) continue;
//		cout << u << ' ' << v << ' ' << w << ' ';
		if(fu != fv){
//			cout << "    <-";
			p[fu] = fv;
			now += w;
		} 
		if(now > res) return ;
//		cout << '\n';
	}
//	cout << id << ' ' << now << '\n';
	res = min(res, now);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int i, j, u, v, fu, fv, x;
	read(n), read(m), read(k);
	for (i = 1; i <= m; i ++ ){
		read(e[i].a), read(e[i].b), read(e[i].c); 
	}
	sort(e + 1, e + m + 1);
	for (i = 1; i <= n; i ++ ) p[i] = i;
	for (i = 1; i <= m; i ++ ){
		u = e[i].a, v = e[i].b;
		fu = find(u), fv = find(v);
		if(fu != fv){
			p[fu] = fv;
			ne[ ++ cnt] = e[i]; 
		} 
	}
	for (i = 1; i <= k; i ++ ){
		read(c[i]);
		for (j = 1; j <= n; j ++ ){
			read(x);
			ne[ ++ cnt] = {n + i, j, x};
		}
	}
	sort(ne + 1, ne + cnt + 1);
	for (i = 0; i < 1 << k; i ++ )
		work(i);
	cout << res;
	return 0;
}
