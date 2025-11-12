//GZ-00134 √œΩ‹»Ò 
#include <bits/stdc++.h>

using namespace std;

int n, t, a, b, c;

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		int s1 = 0, s2 = 0, s3 = 0;
		int cnt = 0;
		while (t--) {
			scanf("%d%d%d", &a, &b, &c);
			int sum1 = max(b, c);
			int sum2 = max(a, sum1);
			if (sum2 == a) {
				if (s1 > n / 2) 
					sum2 = max(b, c);
				s1++;
			} else if (sum2 == b) {
				if (s2 > n / 2)
					sum2 = max(a, c);
				s2++;
			} else if (sum2 == c) {
				if (s3 > n / 2)
					sum2 = max(a, b);
				s3++;
			}
			cnt += sum2;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
