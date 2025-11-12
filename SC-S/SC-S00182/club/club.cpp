#include <bits/stdc++.h>
#define ll long long
#define gc getchar
#define pc putchar

using namespace std;
const int N = 1e5 + 5;

inline ll rd(){
	ll x = 0, f = 1; char c = gc();
	while(! isdigit(c)){if(c == '-')f = - f; c = gc();}
	while(isdigit(c)){x = (x << 3) + (x << 1) + (c ^ 48); c = gc();}
	return x * f;
}
inline void wt(ll x){
	if(x < 0)pc('-'), x = - x; static short st[20], top(0);
	do st[++top] = x % 10, x /= 10; while(x);
	while(top)pc(st[top--] ^ 48);
}

int n, o, cnt[3];
struct node{int b[3];}a[N], d[3][N];
ll s;

inline int i1(int x){return (x + 1) % 3;}
inline int i2(int x){return (x + 2) % 3;}
inline int val(node x){return max(x.b[i1(o)] - x.b[o], x.b[i2(o)] - x.b[o]);}
inline bool cmp(node x, node y){return val(x) > val(y);}

inline void sol(){
	n = rd(); o = - 1; cnt[0] = cnt[1] = cnt[2] = s = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < 3; ++j)a[i].b[j] = rd();
	for(int i = 1; i <= n; ++i){
		int k = 0; for(int j = 1; j < 3; ++j)
			if(a[i].b[k] < a[i].b[j])k = j;
		s += a[i].b[k]; d[k][++cnt[k]] = a[i];
	}
	for(int i = 0; i < 3; ++i)if(cnt[i] * 2 >= n){o = i; break;}
	if(o < 0)return wt(s), pc('\n'), void();
	sort(d[o] + 1, d[o] + 1 + cnt[o], cmp);
	int m = cnt[o] - n / 2;
	for(int i = 1; i <= m; ++i)s += val(d[o][i]);
	wt(s); pc('\n');
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for(int T = rd(); T--; )sol();
	return 0;
}