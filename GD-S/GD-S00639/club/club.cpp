#include<bits/stdc++.h>
using namespace std; 
const int N = 1e5 + 5; 
#define ll long long
int inline read() {
	int num = 0, f = 1; 
	char ch = getchar(); 
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { num = (num << 3) + (num << 1) + (ch ^ 48); ch = getchar(); }
	return num * f; 
}
int n, cnt, t[N][4], ans; 
struct node { int s, t, m; } d[N];
int solve1(int x, int y, int z) {
	int res = 0; 
	for(int i = 1; i <= n; ++i) {
		int a, b, c; 
		a = t[i][x], b = t[i][y], c = t[i][z]; 
		res += a, b -= a, c -= a; 
		d[i].s = b, d[i].t = c, d[i].m = max(d[i].s, d[i].t); 
	}
	sort(d + 1, d + 1 + n, [](node A, node B) { return A.m > B.m; } ); 
	for(int i = 1; i <= n / 2; ++i)
		res += d[i].m; 
	return res; 
}
/*
Warning: 此做法相当于某个钦定选择了 n/2 个。
 
*/
int solve2() {
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, res = 0; 
	for(int i = 1; i <= n; ++i) {
		int a, b, c, m = 0; 
		a = t[i][1], m = max(m, a); 
		b = t[i][2], m = max(m, b); 
		c = t[i][3], m = max(m, c); 
		res += m; 
		if(m == a) ++cnt1; 
		else if(m == b) ++cnt2; 
		else ++cnt3; 
	}
	if(cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2) return res; 
	else return 0; 
}
int main() {
#define file
#ifdef file
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout); 
#endif
	int T = read(); 
	while(T--) {
		n = read(); 
		for(int i = 1; i <= n; ++i) 
			for(int j = 1; j <= 3; ++j)
				t[i][j] = read(); 
		ans = solve2(); 
		ans = max(ans, solve1(1, 2, 3)); 
		ans = max(ans, solve1(2, 1, 3)); 
		ans = max(ans, solve1(3, 1, 2)); 
		printf("%d\n", ans); 
	}
	return 0; 
}
/*
最佳方案中：
1. 三个都没超过一半，应该可以用贪心找到？
2. 超过一半，则调整？ 

1
30
6090 4971 4101
14495 19657 10011
6294 14948 17496
3266 18897 6963
3129 14412 12639
5331 7102 7590
12533 15635 16270
2339 16892 11211
6980 3113 19980
16859 13322 9404
16742 1573 8946
1285 5253 2697
18072 16412 5595
15870 17311 7711
19194 4644 11192
1306 6558 10317
11128 16814 5947
1603 6202 15251
4014 5797 2498
1557 4235 12431
1561 16149 16433
9399 1760 809
13383 18379 10169
7679 4131 17310
2900 8148 13627
14783 19510 17642
19717 4666 6335
9868 5451 19561
11196 1774 11436
10753 10148 6994

*/
