#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct People {
	int x, y, z;
} a[N];

bool no1, no2, no3;
int t, n, ans;
void dfs(int x, int c1, int c2, int c3, int sum) {
	if (x == n + 1) {
		ans = max(ans, sum);
		return;
	}
	
	if (c1 < n / 2) dfs(x + 1, c1 + 1, c2, c3, sum + a[x].x);
	if (c2 < n / 2) dfs(x + 1, c1, c2 + 1, c3, sum + a[x].y);
	if (c3 < n / 2) dfs(x + 1, c1, c2, c3 + 1, sum + a[x].z);
}

bool cmp(People a, People b) {
	return max({a.x, a.y, a.z}) > max({b.x, b.y, b.z});
}

int main() {
	int i;
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 1; i <= n; ++i) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		
		if (n < 30) {
			dfs(1, 0, 0, 0, 0);
			printf("%d\n", ans);
		}
		else {
			sort(a + 1, a + 1 + n, cmp);
		
			int k = 1, c1 = 0, c2 = 0, c3 = 0, s1 = 0, s2 = 0, s3 = 0;
			while (1) {
				bool change = 0;
				
				for (i = k; i <= n; ++i) {
					if (!no1 && max({a[i].x, a[i].y, a[i].z}) == a[i].x) {
						if (c1 < n / 2) ++c1, s1 += a[i].x, ++k;
						else {
							change = 1, no1 = 1;
							break;
						}
					}
					else if (!no2 && max({a[i].x, a[i].y, a[i].z}) == a[i].y) {
						if (c2 < n / 2) ++c2, s2 += a[i].y, ++k;
						else {
							change = 1, no2 = 1;
							break;
						}
					}
					else if (!no3) {
						if (c3 < n / 2) ++c3, s3 += a[i].z, ++k;
						else {
							change = 1, no3 = 1;
							break;
						}
					}
				}
				
				if (change) {
					for (i = k; i <= n; ++i) {
						if (no1) a[i].x = -1;
						else if (no2) a[i].y = -1;
						else if (no3) a[i].z = -1;
					}
					sort(a + k, a + 1 + n, cmp);
				}
				else break;
			}
			
			printf("%d\n", s1 + s2 + s3);
		}
		
		ans = 0;
	}

	return 0;
}

