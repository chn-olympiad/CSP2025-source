#include <bits/stdc++.h>
using namespace std;
int a[120], m, n, ans, cnt, pos;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m * n; i++)	scanf("%d", &a[i]);
	ans = a[1];
	sort(a, a + 120);
	for (int k = 119; k >= 120 - m * n; k--)
		if (a[k] == ans)
			cnt = 120 - k;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			pos++;
			if (pos == cnt){
				if (i % 2 == 1)	printf("%d %d", i, j);
				else	printf("%d %d", i, n - j + 1);
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
