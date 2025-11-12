#include <bits/stdc++.h>
using namespace std;
int n, t, q, w, e, s;
struct ed{
	int f, s, t; bool flag;
}a[100005];
bool cmp1(ed a, ed b){return a.f > b.f;}
bool cmp2(ed a, ed b){return a.s > b.s;}
bool cmp3(ed a, ed b){return a.t > b.t;}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++){
		s = 0, q = 0, w = 0, e = 0;
		for (int j = 1; j <= 100005; j++) a[j].flag = 1;
		cin >> n;
		for (int j = 1; j <= n; j++) cin >> a[j].f >> a[j].s >> a[j].t;
		sort(a + 1, a + n + 1, cmp1);
		for (int j = 1; j <= n; j++){
			if (!a[j].flag) continue;
			if (a[j].f == max(a[j].f, max(a[j].s, a[j].t))){
				if (q + 1 <= n / 2){q++; a[j].flag = 0; s += a[j].f; cout << a[j].f << ' ';}
			}
			else a[j].f = a[j].s - 1;
		}
		sort(a + 1, a + n + 1, cmp2);
		for (int j = 1; j <= n; j++){
			if (!a[j].flag) continue;
			if (a[j].s == max(a[j].f, max(a[j].s, a[j].t))){
				if (w + 1 <= n / 2){w++; a[j].flag = 0; s += a[j].s; cout << a[j].s << ' ';}
			}
			else a[j].s = a[j].t - 1;
		}
		sort(a + 1, a + n + 1, cmp3);
		for (int j = 1; j <= n; j++){
			if (!a[j].flag) continue;
			if (a[j].t == max(a[j].f, max(a[j].s, a[j].t))){
				if (e + 1 <= n / 2){e++; a[j].flag = 0; s += a[j].t; cout << a[j].t << ' ';}
			}
		}
		cout << s << '\n';
	}
	return 0;
}
