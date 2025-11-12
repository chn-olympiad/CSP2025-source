#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
std::vector<int> scores;
int Rscore;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int score;
			std::cin >> score;
			scores.emplace_back(score);
		}
	}
	Rscore = scores[0];

	std::sort(scores.begin(), scores.end(), std::greater<int>());
	int curX = 1, curY = 1, direction = 1;
	for (const auto& score : scores) {
		if (score == Rscore) {
			break;
		}

		curX += direction;
		if (curX <= 0 || curX > n) {
			curX -= direction;
			++curY;
			direction = -direction;
		}
	}

	std::cout << curY << " " << curX << std::endl;

	return 0;
}
