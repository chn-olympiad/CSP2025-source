#include<bits/stdc++.h>
#define endl '\n'
#define pi piar<int, int>
#define ll long long

using namespace std;
const int mod = 1e9 + 7;
const int N = 1e1 + 10;
int n, m, a[N * N], k, cnt, num;

void dfs(int x, int y, int step, bool flag, bool end) { // flag : 0/1 => up/down
	if (end == true) return ;
	bool f = end;
	if (step == cnt || step == num) {
		cout << y << " " << x << endl;
		f = true;
		return ;
	}
	if (x == 1 && flag == false) return dfs(x, y + 1, step + 1, true, f);
	else if (x == n && flag == true) return dfs(x, y + 1, step + 1, false, f);
	if (flag == true) return dfs(x + 1, y, step + 1, flag, f);
	else return dfs(x - 1, y, step + 1, flag, f);
	return ;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	cnt = n * m;
	for (int i = 1; i <= cnt; i++) cin >> a[i];
	k = a[1];
	sort(a + 1, a + 1 + cnt, greater<int>());
	num = lower_bound(a + 1, a + 1 + cnt, k, greater<int>()) - a;
	dfs(1, 1, 1, true, false);
	return 0;
}

