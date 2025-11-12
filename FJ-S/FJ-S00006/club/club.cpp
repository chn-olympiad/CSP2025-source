#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		int n, a[100006][4], max_1 = 0, max_2 = 0, max_3 = 0, m[100006][4], sum = 0;
		scanf("%d", &n);
		for (int i = 1;i <= n;i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
				max_1++, sum += a[i][1], m[i][0] = 1, m[i][1] = min(a[i][1] - a[i][2], a[i][1] - a[i][3]);
			else if (a[i][2] >= a[i][3])
				max_2++, sum += a[i][2], m[i][0] = 2, m[i][2] = min(a[i][2] - a[i][1], a[i][2] - a[i][3]);
			else max_3++, sum += a[i][3], m[i][0] = 3, m[i][3] = min(a[i][3] - a[i][2], a[i][3] - a[i][1]);
		}
		if (max_1 > n / 2) {
			int q[100006], jishu = 0;
			for (int i = 1;i <= n;i++) {
				if (m[i][0] == 1)
					q[++jishu] = m[i][1];
			}
			sort(q + 1, q + jishu + 1);
			for (int i = 1;i <= max_1 - n / 2;i++)
				sum -= q[i];
		} else if (max_2 > n / 2) {
			int q[100006], jishu = 0;
			for (int i = 1;i <= n;i++) {
				if (m[i][0] == 2)
					q[++jishu] = m[i][2];
			}
			sort(q + 1, q + jishu + 1);
			for (int i = 1;i <= max_2 - n / 2;i++)
				sum -= q[i];
		} else if (max_3 > n / 2) {
			int q[100006], jishu = 0;
			for (int i = 1;i <= n;i++) {
				if (m[i][0] == 3)
					q[++jishu] = m[i][3];
			}
			sort(q + 1, q + jishu + 1);
			for (int i = 1;i <= max_3 - n / 2;i++)
				sum -= q[i];
		}
		printf("%d\n", sum);
	}
}
