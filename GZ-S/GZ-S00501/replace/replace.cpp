// 准考证：GZ-S00501，姓名：黄佳洛，学校：华中师大一附中贵阳学校 

#include <bits/stdc++.h>
#define endl '\n'
#define upp(i, l, r) for (int i = l; i <= r; i++)
#define dww(i, r, l) for (int i = r; i >= l; i--)
#define IO ios::sync_with_stdio(0)
#define x first
#define y second
#define PII pair<int, int>

using namespace std;

const int N = 1e6 + 10;

int n, m;
string p, w;
map<string, string> mp;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> m;
	int maxn = 0, minn = 1e9;
	upp(i, 1, n) {
		cin >> w >> p;
		mp[w] = p;
		maxn = max(maxn, (int)p.size());
		minn = min(minn, (int)p.size());
	}
	
	upp(i, 1, m) {
		cin >> w >> p;
		cout << 0 << endl;
	}
	
	return 0;
}
