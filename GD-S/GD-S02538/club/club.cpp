#include <iostream>
#include <algorithm>

#define Nahida return 0

int T;
int n, a[100005][3];
int ans;
bool spec;
int c[3];

void dfs(int depth, int sum) {
	if (depth > n) {
		ans = std::max(ans, sum);
		return;
	}
	
	for (int i = 0; i != 3; ++i) {
		if (c[i] < n / 2) {
			++c[i];
			dfs(depth + 1, sum + a[depth][i]);
			--c[i];
		}
	}
	return;
}
void fd(void) {
	int p[100005];
	for (int i = 1; i <= n; ++i) {
		p[i] = a[i][0];
	}
	std::sort(p + 1, p + n + 1, std::greater<int>());
	for (int i = 1; i <= n / 2; ++i) {
		ans += p[i];
	}
	return;
}

int main(void) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	std::cin >> T;
	while (T--) {
	
	ans = 0;
	c[0] = c[1] = c[2] = 0;
	spec = true;
	
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i][0] >> a[i][1] >> a[i][2];
		if (a[i][1] != 0 || a[i][2] != 0) {
			spec = false;
		}
	}
	if (spec) {
		fd();
	} else {
		dfs(1, 0);
	}
	std::cout << ans << '\n';
	
	} // Line 12 || while (T--) 
	
	fclose(stdin);
	fclose(stdout);
	Nahida;
}
