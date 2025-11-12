#include <stdio.h>
#define SIZE 500010
int n, k, cnt;
int in, arr[SIZE], dp[SIZE];
int que, len, head, tail;
bool t = true;
bool check(int L, int R, int l, int r) {
	return !(L < r) ^ (R < l);
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", arr + i);
		if (arr[i] > 1) t = false;
		dp[i] = dp[i - 1] ^ arr[i];
	}
	if (t) {
		switch (k) {
			case 0:
				for (int i = 1; i <= n; i++) {
					if (arr[i] == 0) cnt++;
					if (arr[i] == 1 && arr[i + 1] == 1) cnt++, i++;
				}
				break;
			case 1:
				for (int i = 1; i <= n; i++) if (arr[i] == 1) cnt++;
				break;
		}
	} else { //error
		tail = 1;
		for (int i = 1; i <= n; i++) {
			que ^= arr[i];
			if (que == k) {
				cnt++, tail = i + 1;
				continue;
			}
			if (que == 0) que ^= arr[tail++];
		}
	}
	printf("%d", cnt);
	return 0;
}