#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 5;

int test_case, n, arr[N][4], Index[N];
long long suf[N];
long long answer;
bool swapped[N];

struct Node {
	int weight, p;
	bool operator<(const Node& rhs) const {
		if (weight != rhs.weight) return weight > rhs.weight;
		return arr[p][2] < arr[rhs.p][2];
	}
};

void Dfs(const int pos, const long long sum, const int c1, const int c2, const int c3) {
	if (sum + suf[pos] < answer) return;
	
	if (pos > n) {
		answer = max(answer, sum);
		return;
	}
	
	if (c1 < n / 2) Dfs(pos + 1, sum + arr[pos][1], c1 + 1, c2, c3);
	if (c2 < n / 2) Dfs(pos + 1, sum + arr[pos][2], c1, c2 + 1, c3);
	if (c3 < n / 2) Dfs(pos + 1, sum + arr[pos][3], c1, c2, c3 + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> test_case;
	
	while (test_case--) {
		cin >> n;
		
		bool flag1 = true, flag2 = true;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
			
			flag1 = flag1 && arr[i][2] == 0 && arr[i][3] == 0;
			flag2 = flag2 && arr[i][3] == 0;
		}
		
		if (flag1 == true) {
			for (int i = 1; i <= n; i++) {
				Index[i] = i;
			}
			sort(Index + 1, Index + n + 1, [&] (int a, int b) {
				return arr[a][1] > arr[b][1];
			});
			
			answer = 0;
			for (int i = 1; i <= n / 2; i++) {
				answer += arr[i][1];
			}
			
			cout << answer << "\n";
			continue;
		}
		
		suf[n + 1] = 0;
		for (int i = n; i >= 1; i--) {
			suf[i] = suf[i + 1] + max({arr[i][1], arr[i][2], arr[i][3]});
		}
		
		answer = 0;
		Dfs(1, 0, 0, 0, 0);
		
		cout << answer << "\n";
	}
	
	return 0;
}
