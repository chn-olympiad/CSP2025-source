#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const int a, const int b);
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<int> exam(n * m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> exam[i * n + j];
		}
	}
	int ans = exam[0];
	sort(exam.begin(), exam.end(), cmp); 
	int k = 0;
	int i = 0, j = 0;
	while(true) {
		if (k == n * m - 1) {
			a[i][j] = exam[k];
			break;
		}
		if (i == (n - 1) && (j % 2) == 0) {
			a[i][j] = exam[k];
			++j;
		} else if (i == 0 && j % 2 == 1) {
			a[i][j] = exam[k];
			++j;
		} else if (j % 2 == 0) {
			a[i][j] = exam[k];
			++i;
		} else if (j % 2 == 1) {
			a[i][j] = exam[k];
			--i;
		}
		++k;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == ans) {
				cout << j + 1 << " " << i + 1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

bool cmp(const int a, const int b) {
	return a > b;
}