#include<bits/stdc++.h>

const int N = 110;
int A[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++)
		scanf("%d", A + i);
	int A1 = A[1];
	std::sort(A + 1, A + 1 + n * m, std::greater<int>());
	int num = std::lower_bound(A + 1, A + 1 + n * m, A1, std::greater<int>()) - A - 1;
	int row = num / n + 1;
	if(row & 1)
		printf("%d %d\n", row, num % n + 1);
	else
		printf("%d %d\n", row, n - (num % n));
	return 0;
}

