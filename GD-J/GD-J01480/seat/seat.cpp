#include <bits/stdc++.h>

int main() {
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
	int N, M, val, val2, cnt = 1;
	std::cin >> N >> M >> val;
	for (int i = 1; i < N * M; i ++) std::cin >> val2, cnt += val2 > val;
	int ansx = (cnt - 1) / M + 1;
	int ansy = (ansx & 1 ? (cnt - 1) % M + 1 : (N - (cnt - 1) % M));
	std::cout << ansx << " " << ansy;
	return 0;
}
