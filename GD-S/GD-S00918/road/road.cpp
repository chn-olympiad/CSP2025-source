#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , m , k , f[10010] , c[20][10010];
struct road {
	int x , y , num;
} a[2000010] , b[2000010];
bool cmp (road a , road b) {
	return a.num < b.num;
}
int fa (int id) {
	if (f[id] == id) return id;
	return f[id] = fa (f[id]);
}
int min_road (int n , int m) {
	for (int i = 1;i <= n;i ++) f[i] = i;
	int ans = 0;
	sort (a + 1 , a + m + 1 , cmp);
	for (int i = 1;i <= m;i ++) {
		int x = a[i].x , y = a[i].y , num = a[i].num;
		int xx = fa (x) , yy = fa (y);
		if (xx == yy) continue;
		else {
			f[xx] = yy;
			ans += num;
		}
	}
	return ans;
}
int get_ans (int x) {
	int sum = 0 , num = m , tot = n;
	for (int i = 1;i <= m;i ++) {
		a[i].x = b[i].x; a[i].y = b[i].y; a[i].num = b[i].num;
	}
	for (int i = 0;i < k;i ++) {
		if ((1 << i) & x) {
			tot ++;
			sum += c[i + 1][0];
			for (int j = 1;j <= n;j ++) {
				num ++;
				a[num].x = tot;
				a[num].y = j;
				a[num].num = c[i + 1][j];
			}
		}
	}
	return sum + min_road (tot , num);
}
signed main () {
	freopen ("road.in" , "r" , stdin);
	freopen ("road.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i ++) {
		cin >> a[i].x >> a[i].y >> a[i].num;
		b[i].x = a[i].x; b[i].y = a[i].y; b[i].num = a[i].num;
	}
	for (int i = 1;i <= k;i ++) {
		for (int j = 0;j <= n;j ++) {
			cin >> c[i][j];
		}
	}
	if (k <= 5) {
		int ans = LLONG_MAX;
		for (int i = 0;i < (1 << k);i ++) ans = min (ans , get_ans (i));
		cout << ans;
		return 0;
	}
	
	
	return 0;
} 
