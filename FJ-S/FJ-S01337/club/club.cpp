#include <cstdio>
#include <iostream>
using namespace std;

long long result, n;
int students[100005][3];

void dfs(int i, int a, int n1, int n2, int n3) {
	if (i == n) {
		if (a > result) result = a;
		return;
	}
	if (n1) dfs(i + 1, a + students[i][0], n1 - 1, n2, n3);
	if (n2) dfs(i + 1, a + students[i][1], n1, n2 - 1, n3);
	if (n3) dfs(i + 1, a + students[i][2], n1, n2, n3 - 1);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		cin >> n;
		result = 0;
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < 3; j ++)
				cin >> students[i][j];
		if (n >= 200) {
			if (students[0][2] == 0) dfs(0, 0, n / 2, n / 2, 0);
			else if (students[0][2] == 0 && students[0][1] == students[0][2]) dfs(0, 0, n / 2, 0, 0);
		} else dfs(0, 0, n / 2, n / 2, n / 2);
		cout << result << endl;
	}
	return 0;
} 
