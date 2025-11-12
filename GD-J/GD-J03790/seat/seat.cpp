#include <iostream>
#include <queue>

int n, m, user;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	std::priority_queue<int> list;
	std::cin >> n >> m >> user;
	list.push(user);
	
	for (int i = 1 ; i < n*m ; ++i) {
		int input;
		std::cin >> input;
		list.push(input);
	}
	
	int i = 1, j = 1, ans = 1;
	while (!list.empty()) {
		// std::cout << "[Player " << ans++ << "] i: " << i << "\tj: " << j << "\tContent: " << list.top()  << std::endl;

		if (list.top() == user) break;

		if (j % 2) {
			if (i + 1 > n)
				++j;
			else ++i;
		}
		else {
			if (i - 1 < 1)
				++j;
			else --i;
		}
		
		list.pop();
	}
	
	std::cout << j << " " << i << std::endl;
	
	fclose(stdin);
	fclose(stdout);
}
