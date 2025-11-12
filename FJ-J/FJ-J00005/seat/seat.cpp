#include <bits/stdc++.h>
using namespace std;
int n, m, a[106], C, R, b[106];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n * m;i++)
		scanf("%d", &b[i]);
	int r = b[1];
	sort(b + 1, b + n * m + 1);
	for (int i = n * m;i >= 1;i--)
		a[n * m - i + 1] = b[i];
	for (int i = 1;i <= n * m;i++)
		if (r == a[i])
			r = i;
	int s = 0, flag = 0;
	for (int i = 1;i <= m;i++) {
		if (i % 2 == 1) {
			for (int j = 1;j <= n;j++){
				s++;
				if (r == s)
					flag = 1, C = i, R = j;
			}
		} else {
			for (int j = n;j >= 1;j--){
				s++;
				if (r == s)
					flag = 1, C = i, R = j;
			}
		}
		if (flag != 0)
			break;
	}
	printf("%d %d", C, R);
}
