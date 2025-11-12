#include <climits>
#include <iostream>

#define ll long long int

using std::cout; using std::cin;

const int N = 1e5 + 10, inf = 0x3f3f3f3f;

unsigned int s[N][4];
unsigned int number[4];
unsigned int group[N];

unsigned int n;
unsigned int number_max;
unsigned int ans;

void dfs(unsigned int sum, unsigned int id) {

	if (id >= n + 1) {
		// update ans when we have scanned all of the members.
		/*
		if (sum > ans) {
			ans = sum;
			for (unsigned int i = 1; i <= n; ++i)
				cout << group[i] << " ";
			cout << '\n';
		}
		*/
		ans = std::max(ans, sum);
		return ;
	}

	for (unsigned int grp = 1; grp <= 3; ++grp) {
		unsigned int cur_s = s[id][grp];
		// put current member into grp.
		group[id] = grp;
		if (number[grp] + 1 > number_max) {
			//cout << "failed when we tried to put " << id << " to " << grp << ",number[grp] is " << number[grp] << '\n';
			continue;
		}
		++number[grp];

		dfs(sum + cur_s, id + 1);
		// let current member come out from grp.
		--number[grp];
	}
}

void solve() {
	cin >> n;
	// n % 2 == 0 is true in this problem.
	number_max = n / 2;

	ans = 0;

	number[1] = number[2] = number[3] = 0;
	for (unsigned int i = 1; i <= n; ++i)
		cin >> s[i][1] >> s[i][2] >> s[i][3];

	dfs(0, 1);

	cout << ans << '\n';
}

int main() {
	
	std::ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}

