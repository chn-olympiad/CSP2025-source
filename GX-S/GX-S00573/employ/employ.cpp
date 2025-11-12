#include <iostream>

#define ui unsigned int
#define ll long long int
#define ull unsigned ll

using std::cout; using std::cin;

const int N = 505, inf = 0x3f3f3f3f, mod = 998244353;

ui n, m;
ui c[N]; std::string s;
ui a[N];
bool book[N];

ull ans;

void dfs(ui id, ui cse) {

	//cout << id << " " << cse << '\n';

	//cout << cse << " has chose! (^-^)\n";
	a[cse] = id;

	if (id >= n) {
		ui res = 0;
		ui die = 0;
		//cout << "moni...\n";
		//for (ui i = 1; i <= n; ++i) cout << a[i] << " ";
		//cout << '\n';
		for (ui i = 1; i <= n; ++i) {
			ui p = a[i];
			ui cc = c[p];
			if (die >= cc) {
				++die;
				//cout << p << " has died ;-;\n";
				continue;
			}
			if (s[i] == '0') {
				++die;
				//cout << p << " has died ;-;\n";
				continue;
			}
			++res;
		}
		//cout << "moni end!\n";
		if (res >= m) ++ans;
		res %= mod;
		return ;
	}

	book[cse] = true;
	for (ui i = 1; i <= n; ++i) {
		if (book[i]) continue;
		dfs(id + 1, i);
	}
	book[cse] = false;
}

int main() {

	std::ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	for (ui i = 1; i <= n; ++i) cin >> c[i];

	if (m == 1) {
		for (ui i = 2; i <= n; ++i) ans *= i, ans %= mod;
	} else {
		dfs(0, 0);
	}

	cout << ans << '\n';

	return 0;
}

