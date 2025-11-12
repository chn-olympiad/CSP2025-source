#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
std::vector<int> scores;
int score_of_xiaoming;
int main() {
	std::freopen("seat.in", "r", stdin);
	std::freopen("seat.out", "w", stdout);
	
	int n, m;
	std::cin >> n >> m;
	
	const int people_amount = m * n;
	for (int i = 0;i < people_amount;i++) {
		int score;
		std::cin >> score;
		scores.emplace_back(score);
	}
	score_of_xiaoming = scores[0];
	std::sort(scores.begin(), scores.end(), std::greater<int>());
	auto place = std::find(scores.begin(), scores.end(), score_of_xiaoming) - scores.begin() + 1;
	int row = std::ceil(1.0 * place / n);
	int line = place;
	line -= (row - 1) * n;
	if (row % 2 == 0) {
		line = n - line + 1;
	}
	std::cout << row << " " << line;
	
	std::fclose(stdin);
	std::fclose(stdout);
	return 0;
}