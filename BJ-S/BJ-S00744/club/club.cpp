#include <bits/stdc++.h>
using namespace std;
struct node{
	int a, b, c, mx, mi, x, y;
} a[100010];
bool cmp(node x, node y){
	return x.y > y.y;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T, n;
	cin >> T;
	while (T--){
		int c1 = 0, c2 = 0, c3 = 0, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].mx = max({a[i].a, a[i].b, a[i].c});
			a[i].mi = min({a[i].a, a[i].b, a[i].c});
			a[i].x = a[i].a ^ a[i].b ^ a[i].c ^ a[i].mx ^ a[i].mi;
			a[i].y = a[i].mx - a[i].x;
		}
		sort(a+1, a+n+1, cmp);
		for (int i = 1; i <= n; i++){
			if (a[i].mx == a[i].a && c1 < n/2){
				c1++;
				ans += a[i].mx;
				continue;
			}
			if (a[i].mx == a[i].b && c2 < n/2){
				c2++;
				ans += a[i].mx;
				continue;
			}
			if (a[i].mx == a[i].c && c3 < n/2){
				c3++;
				ans += a[i].mx;
				continue;
			}
			if (a[i].x == a[i].a){
				c1++;
				ans += a[i].x;
			}
			if (a[i].x == a[i].b){
				c2++;
				ans += a[i].x;
			}
			if (a[i].x == a[i].c){
				c3++;
				ans += a[i].x;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
