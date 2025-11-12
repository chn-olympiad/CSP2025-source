#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 5e5 + 5;

int n, k, arr[maxn];
bool A;
void Input() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
		if (arr[i] != 1) {
			A = true;
		}
	}
}

int ans;
void DFS(int cnt, int st) {
	for (int i = st; i <= n; ++i) {
		int sum = arr[i];
		if (sum == k) {
			DFS(cnt + 1, i + 1);
			return;
		}
		for (int j = i + 1; j <= n; ++j) {
			sum ^= arr[j];
			if (sum == k) {
				DFS(cnt + 1, j + 1);
			}
		}
	}
	ans = max(ans, cnt);
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	Input();
	if (A == false) {
		printf("%d", n / 2);
		return 0;
	}
	DFS(0, 1);
	printf("%d", ans);
	return 0;
}