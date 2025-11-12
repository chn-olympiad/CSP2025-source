#include <bits/stdc++.h>
#define LL long long
#define fu(x , y , z) for(int x = y ; x <= z ; x ++)
using namespace std;
const int N = 1e4 + 5 , M = 1e6 + 5;
int n , m , K , fa[N << 1] , cnt , a1 , b1;
LL ans , c[15] , mp[15][N];
struct E {
	int u , v;
	LL w;
} e[M << 1] , a[M] , b[M];
bool cmp (E x , E y) { return x.w < y.w; }
int find (int x) {
	if (x == fa[x]) return x;
	else return fa[x] = find (fa[x]);
}
LL sol () {
	LL sum = 0;
	sort (e + 1 , e + cnt + 1 , cmp);
	fu (i , 1 , n << 1) fa[i] = i;
	int fa1 , fa2 , u , v;
	LL w;
	fu (i , 1 , cnt) {
		u = e[i].u , v = e[i].v , w = e[i].w;
		fa1 = find (u) , fa2 = find (v);
		if (fa1 == fa2) continue;
		fa[fa1] = fa2;
		sum += w;
	}
	return sum;
}
void pre () {
	fu (i , 1 , n) fa[i] = i;
	sort (a + 1 , a + a1 + 1 , cmp);
	int fa1 , fa2 , u , v;
	fu (i , 1 , a1) {
		fa1 = fa[1];
		u = a[i].u , v = a[i].v;
		fa1 = find (u) , fa2 = find (v);
		if (fa1 == fa2) continue;
		fa[fa1] = fa2;
		b[++b1] = a[i];
	}
	return;
}
int main () {
	freopen ("road.in" , "r" , stdin);
	freopen ("road.out" , "w" , stdout);
	scanf ("%d%d%d" , &n , &m , &K);
	fu (i , 1 , m) {
		int u , v;
		LL w;
		scanf ("%d%d%lld" , &u , &v , &w);
		a[++a1] = {u , v , w};
	}
	pre ();
	a1 = b1;
	fu (i , 1 , a1) a[i] = b[i];
	fu (i , 1 , K) {
		scanf ("%lld" , &c[i]);
		fu (j , 1 , n) {
			scanf ("%lld" , &mp[i][j]);
		}
	}
//	if (K <= 5) {
		LL sum;
		ans = 1e18;
		int k1 = (1 << K) - 1;
		fu (i , 0 , k1) {
			cnt = 0;
			fu (j , 1 , a1) e[++cnt] = a[j];
			sum = 0;
			fu (j , 1 , K) {
				if ((i >> (j - 1)) & 1) {
				sum += c[j];
					fu (k , 1 , n) e[++cnt] = {k , j + n , mp[j][k]};
				}
			}
//			cout << cnt << "\n";
			sum += sol ();
			ans = min (ans , sum);
//			printf ("%lld\n" , ans);
		}
		printf ("%lld" , ans);
//	}
	return 0;
}
