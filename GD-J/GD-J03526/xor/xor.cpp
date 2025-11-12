#include <iostream>
#include <queue>
using namespace std;
int Xor[200005], a[200005], n, k, maxn, f[200005];
queue<int> x;
queue<int> ans;
void bfs() {
	int s = 0;
	x.push(s++);
	ans.push(0);
	while(!x.empty()) {
		if(s <= n) {
			x.push(s++);
			ans.push(0);
		}
		for(int i = x.front(); i <= n; i++) {
			if((Xor[x.front() - 1] xor Xor[i]) == k) {
				//cout << x.front() << "~" << i << " " << ans.front() + 1 << endl;
				if(f[i + 1] >= ans.front() + 1) {
					continue;
				} else {
					f[i + 1] = ans.front() + 1;
				}
				maxn = max(maxn, ans.front() + 1);
				ans.push(ans.front() + 1);
				x.push(i + 1);
				x.push(x.front() + 1);
				ans.push(ans.front());
				break;
			}
		}
		ans.pop();
		x.pop();
	}
	return;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		Xor[i] = Xor[i - 1] xor a[i];
	}
	bfs();
	cout << maxn << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
