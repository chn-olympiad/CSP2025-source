#include <bits/stdc++.h>
using namespace std;

int T, n, vis[100010], pt1[100010], pt2[100010];
array<int, 2> p1[100010], p2[100010];
array<int, 3> a[100010];

int main(){
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf ("%d", &T);
	for (; T--; ){
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf ("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			ans += a[i][0];
		for (int i = 1; i <= n; i++){
			p1[i] = {-a[i][0] + a[i][1], i};
			p2[i] = {-a[i][0] + a[i][2], i};
		}
		sort(p1 + 1, p1 + n + 1);
		reverse(p1 + 1, p1 + n + 1);
		sort(p2 + 1, p2 + n + 1);
		reverse(p2 + 1, p2 + n + 1);
		for (int i = 1; i <= n; i++)
			vis[i] = 0;
		int r1 = 1, r2 = 1, m1 = 0, m2 = 0;
		for (; m1 + m2 < n / 2 || (r1 <= n && p1[r1][0] > 0) || (r2 <= n && p2[r2][0] > 0); ){
			if (r2 > n || (r1 <= n && p1[r1] >= p2[r2])){
				int idx = p1[r1][1];
				ans += p1[r1][0], ++vis[idx];
				pt2[++m1] = max(-a[idx][1] + a[idx][2], -a[idx][1] + a[idx][0]);
				++r1;
			}
			else{
				int idx = p2[r2][1];
				ans += p2[r2][0], ++vis[idx];
				pt1[++m2] = max(-a[idx][2] + a[idx][1], -a[idx][2] + a[idx][0]);
				++r2;
			}
			for (; r1 <= n && vis[p1[r1][1]]; r1++);
			for (; r2 <= n && vis[p2[r2][1]]; r2++);
		}
		if (m1 <= n / 2 && m2 <= n / 2)
			printf ("%lld\n", ans);
		else
			if (m1 > n / 2){
				sort(pt2 + 1, pt2 + m1 + 1);
				reverse(pt2 + 1, pt2 + m1 + 1);
				for (int i = 1; i <= m1 - n / 2; i++)
					ans += pt2[i];
				printf ("%lld\n", ans);
			}
			else{
				sort(pt1 + 1, pt1 + m2 + 1);
				reverse(pt1 + 1, pt1 + m2 + 1);
				for (int i = 1; i <= m2 - n / 2; i++)
					ans += pt1[i];
				printf ("%lld\n", ans);				
			}
	}
	return 0;
}
