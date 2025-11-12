#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

struct node {
	int a, b, c;	
} a[N];

int T, n;

inline bool cmp1(node a, node b) {
	int x = max(a.a, max(a.b, a.c)), z = min(a.a, min(a.b, a.c));
	int y = (a.a + a.b + a.c) - x - z;
	int l = max(b.a, max(b.b, b.c)), k = min(b.a, min(b.b, b.c));
	int j = (b.a + b.b + b.c) - l - k;
	//xyz ljk
	
	if (x != l)
		return x > l;
	else if (z != k)
		return z > k;
	else
		return y > j;
}

int dp[N][4];
 
inline void work() {
	vector<pair<int, int>> e1, e2, e3;
	int ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, sum = 0;
	scanf("%d", &n);
	memset(dp, 0, sizeof dp);
	
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
	
	for (int i = 1; i <= n; ++i) {
		int x = max(a[i].a, max(a[i].b, a[i].c)), z = min(a[i].a, min(a[i].b, a[i].c));
		int y = (a[i].a + a[i].b + a[i].c) - x - z;
		
		sum += x;
		
		if (a[i].a == x)
			++cnt1, e1.push_back({x - y, i});
		else if (a[i].b == x)
			++cnt2, e2.push_back({x - y, i});
		else	
			++cnt3, e3.push_back({x - y, i});
	}
	
//	printf("%d %d %d\n", cnt1, cnt2, cnt3);
	
	if (cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) {
		if (cnt1 > n / 2) {
			sort(e1.begin(), e1.end());
			
			for (pair<int, int> i : e1) {
				if (cnt1 <= n / 2)
					break;
					
				sum -= i.first;
				--cnt1;
			}
		} else if (cnt2 > n / 2) {
			sort(e2.begin(), e2.end());
			
			for (pair<int, int> i : e2) {
				if (cnt2 <= n / 2)
					break;
					
				sum -= i.first;
				--cnt2;
				
			}
		} else {
			sort(e3.begin(), e3.end());
			
			for (pair<int, int> i : e3) {
				if (cnt3 <= n / 2)
					break;
					
				sum -= i.first;
				--cnt3;
			}
		}
	}

	printf("%d\n", sum);
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	for (scanf("%d", &T); T; --T)
		work();
		
	return 0;
}

