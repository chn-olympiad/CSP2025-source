#include <bits/stdc++.h>
using namespace std;
int n, k, arr[500005];
int fd[1048576];
int f[500005];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	memset(fd, -1, sizeof fd);
	fd[0] = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", arr + i);
		sum ^= arr[i];
		f[i] = f[i - 1];
		if (~fd[sum ^ k]) f[i] = max(f[i], f[fd[sum ^ k]] + 1);
		fd[sum] = i;
	}
	printf("%d", f[n]);
	return 0;
}
