#include<bits/stdc++.h>
using namespace std;

int T; //mk表示取了第几个 
struct info {
	int first;
	int second;
	int third;
	int mid;
	int cnt;
	int mk;
} stu[100100];

inline bool cmp1(const info &x, const info &y) {
	return x.cnt < y.cnt;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		int n;
		int cnta = 0, cntb = 0, cntc = 0; //分别统计a,b,c的人数 
		long long sum = 0;
		memset(stu, 0, sizeof stu);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &stu[i].first, &stu[i].second, &stu[i].third);
			stu[i].mid = stu[i].first + stu[i].second + stu[i].third;
		}
		for (int i = 1; i <= n; i++) {
			int k = 0, k1 = 1 << 25;
			k = max(k, stu[i].first);
			k = max(k, stu[i].second);
			k = max(k, stu[i].third);
			k1 = min(k1, stu[i].first);
			k1 = min(k1, stu[i].second);
			k1 = min(k1, stu[i].third);
			stu[i].mid = stu[i].mid - k - k1;
			sum += k;
			stu[i].cnt = k - stu[i].mid;
			if (k == stu[i].first) {
				cnta++;
				stu[i].mk = 1;
			}
			else if (k == stu[i].second) {
				cntb++;
				stu[i].mk = 2;
			}
			else if (k == stu[i].third) {
				cntc++;
				stu[i].mk = 3;
			}
		}
		sort(stu + 1, stu + n + 1, cmp1);
		if (cnta > n / 2) {
			for (int i = 1; i <= n; i++) {
				if (cnta <= n / 2)
					break;
				if (stu[i].mk != 1)
					continue;
				if (stu[i].mid == stu[i].second && cntb + 1 <= n / 2) {
					sum -= stu[i].cnt;
					cntb++;
					cnta--;
				}
				else if (stu[i].mid == stu[i].third && cntc + 1 <= n / 2) {
					sum -= stu[i].cnt;
					cntc++;
					cnta--;
				}
			}
		}
		else if (cntb > n / 2) {
			for (int i = 1; i <= n; i++) {
				if (cntb <= n / 2)
					break;
				if (stu[i].mk != 2)
					continue;
				if (stu[i].mid == stu[i].first && cnta + 1 <= n / 2) {
					sum -= stu[i].cnt;
					cnta++;
					cntb--;
				}
				else if (stu[i].mid == stu[i].third && cntc + 1 <= n / 2) {
					sum -= stu[i].cnt;
					cntc++;
					cntb--;
				}
			}
		}
		else if (cntc > n / 2) {
			for (int i = 1; i <= n; i++) {
				if (cntc <= n / 2)
					break;
				if (stu[i].mk != 3)
					continue;
				if (stu[i].mid == stu[i].first && cnta + 1 <= n / 2) {
					sum -= stu[i].cnt;
					cnta++;
					cntc--;
				}
				else if (stu[i].mid == stu[i].second && cntb + 1 <= n / 2) {
					sum -= stu[i].cnt;
					cntb++;
					cntc--;
				}
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
} 
//要用scanf 
