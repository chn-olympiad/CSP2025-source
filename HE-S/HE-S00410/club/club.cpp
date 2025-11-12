#include <bits/stdc++.h>
using namespace std;

int T, n,  xwx, p1, p2, p3;
long long ans;

struct miao{
	int x, y, z, l, ma, mi;
}a[100001];

inline bool cmp(miao p, miao q){
	return p.l > q.l;
}

inline void w2(int p);

inline void w3(int p);

inline void w1(int p){
	if (p1 < xwx){
		p1++;
		ans = ans + a[p].x;
		return;
	}
	if (a[p].y == a[p].mi)
		w3(p);
	else
		w2(p);
	return;
}

inline void w2(int p){
	if (p2 < xwx){
		p2++;
		ans = ans + a[p].y;
		return;
	}
	if (a[p].x == a[p].mi)
		w3(p);
	else
		w1(p);
	return;
}

inline void w3(int p){
	if (p3 < xwx){
		p3++;
		ans = ans + a[p].z;
		return;
	}
	if (a[p].y == a[p].mi)
		w1(p);
	else
		w2(p);
	return;
}

int main(){
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf ("%d", &T);
	while (T--){
		p1 = 0, p2 = 0, p3 = 0,ans = 0;
		scanf ("%d", &n);
		xwx = n / 2;
		for (int i = 1; i <= n; i++){
			scanf ("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
			a[i].ma = max(a[i].x, max(a[i].y, a[i].z));
			a[i].mi = min(a[i].x, min(a[i].y, a[i].z));
			if(a[i].mi == a[i].x){
				if (a[i].ma == a[i].y)
					a[i].mi = a[i].z;
				else
					a[i].mi = a[i].y;
			}
			else
				if(a[i].mi == a[i].y){
					if (a[i].ma == a[i].x)
						a[i].mi = a[i].z;
					else
						a[i].mi = a[i].x;
				}
				else
					if(a[i].mi == a[i].z){
						if (a[i].ma == a[i].y)
							a[i].mi = a[i].x;
						else
							a[i].mi = a[i].y;
					}
			a[i].l = a[i].ma - a[i].mi;
			//printf ("///%d\n", a[i].l);
		}
		sort (a + 1, a + n + 1, cmp);
		for (int i = 1;i <= n; i++){
			if (a[i].ma == a[i].x){
				w1(i);
			}
			else{
				if (a[i].ma == a[i].y)
					w2(i);
				else
					w3(i);
			}
			//printf ("//%d %d %d\n", p1, p2, p3);
			//printf ("/%lld\n", ans);
		}
		printf ("%lld\n", ans);
	}
}
