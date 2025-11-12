#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int read() {
	int x=0,f=1;char chr=getchar();
	while(chr<'0'||'9'<chr){if(chr=='-')f=-f;chr=getchar();}
	while('0'<=chr&&chr<='9'){x=x*10+chr-'0';chr=getchar();}
	return x*f;
}
const int N = 1e4 + 10,M = 1e6 + 10,K = 15;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n,m,k;
ll ans = inf;
struct Edge {
	int x,y,z;
} e[M + N * K];
int c[K];
bool need[N + K],ok = true;
int fa[N + K];
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
void init() {
	n = read(),m = read(),k = read();
	for (int i = 1; i <= m; i++) {
		e[i].x = read(),e[i].y = read(),e[i].z = read();
	}
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		bool tmp = false;
		for (int j = 1; j <= n; j++) {
			e[m + (i - 1) * n + j].x = j,e[m + (i - 1) * n + j].y = n + i,e[m + (i - 1) * n + j].z = read();
			if (e[m + (i - 1) * n + j].z == 0) {
				tmp = true;
			}
		}
		tmp &= c[i] == 0;
		ok &= tmp;
	}
	sort(e + 1,e + m + n * k + 1,[](Edge a,Edge b) {return a.z < b.z;});
	memset(need,1,sizeof(need));
//	for (int i = 1; i <= n; i++) {
//		need[i] = true;
//	}
}
void calc() {
	if (ok) {
		ans = 0;
		for (int j = 1; j <= n + k; j++) {
			fa[j] = j;
		}
		for (int j = 1; j <= m + n * k; j++) {
			int x = e[j].x,y = e[j].y,z = e[j].z;
			if (need[x] == false || need[y] == false) continue;
			if (get(x) == get(y)) continue;
			fa[get(x)] = get(y);
			ans += z;
		}
		cout << ans;
		return;
	}
	ans = inf;
	for (int i = 0; i < (1 << k); i++) {
		ll tmp = 0;
		for (int j = 1; j <= k; j++) {
			if (i >> j - 1 & 1) {
				need[n + j] = true;
				tmp += c[j];
			}
			else {
				need[n + j] = false;
			}
		}
		for (int j = 1; j <= n + k; j++) {
			fa[j] = j;
		}
		for (int j = 1; j <= m + n * k; j++) {
			int x = e[j].x,y = e[j].y,z = e[j].z;
			if (need[x] == false || need[y] == false) continue;
			if (get(x) == get(y)) continue;
			fa[get(x)] = get(y);
			tmp += z;
		}
		ans = min(ans,tmp);
	}
	cout << ans;
}
void solve() {
	init();
	calc();
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}
