#include <iostream>
#include <algorithm>
using namespace std;

string har;
int guar[505],c[505];

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m; cin >> n >> m;
	cin >> har; har = 'G'+har;
	for (int i = 1; i <= n; i++) {
		guar[i] = i; cin >> c[i];
	}
	int ans = 0;
	do {
		int l = 0;
		for (int i = 1; i <= n; i++) {
			if (har[i] == '0') l++;
			else if (l >= c[guar[i]]) l++;
		}
		if (n-l >= m) ans++;
	} while(next_permutation(guar+1,guar+n+1));
	cout << ans;
	return 0;
}
/*
oh不可能要退役了。

本来想正获，没时间了。

T1 无法切除，T2 又没有信心可以 AC。

初二生即将离去，祝我飞升快乐。

回去搞 whk 先把物理开挂的张踩下去。
*/