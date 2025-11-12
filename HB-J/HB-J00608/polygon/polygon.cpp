#include <iostream>
using namespace std;
const int N = 5005;
int main () {
	int n, m [N], max_three = 0, max_four = 0, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m [N];
		max_three = max (max_three, m [i], m [i + 1], m [i + 2]);
		max_four = max (max_four, m [i], m [i + 1], m [i + 2], m [i + 3]);
		if (m [i] + m [i + 1] + m [i + 2] > 2 * max_three) cnt++;
		if (m [i] + m [i + 1] + m [i + 2] + m [i + 3] > 2 * max_four) cnt++;
	}
	cout << cnt;
	return 0;
}
