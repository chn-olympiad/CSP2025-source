#include <iostream>
#include <string>
using namespace std;

string a[200005],b[200005];

/*
飞机天天嗡嗡叫，但不影响心态。

还记得当初军训就在这里，蓝蓝的天上白云飘荡，但是好晒，操场跑道胶皮都化了。

本来想在这里给那个曾经给我吃面包的女孩表白的，但是还是不敢。

啊啊啊，只剩五分钟了，要没了啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊。

168pts 遗憾离场。
*/

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q; cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	while (q--) {
		string x,y;
		cin >> x >> y;
		if (x.size() != y.size()) {
			cout << 0 << endl;
			continue;
		}
		int m = x.size();
		x = 'G'+x;
		y = 'G'+y;
		int p1 = 0, p2 = m+1;
		while (x[p1+1] == y[p1+1]) p1++;
		while (x[p2-1] == y[p2-1]) p2--;
		int cnt = 0;
		for (int i = 0; i <= p1; i++) {
			for (int j = m+1; j >= p2; j--) {
				int l = i+1, r = j-1;
				int len = r-l+1;
				for (int k = 1; k <= n; k++) {
					if (a[k].size() == len) {
						if (x.substr(l,len) == a[k] && y.substr(l,len) == b[k])
							cnt++;
					}
				}
			}
		} 
		cout << cnt << endl;
	}
	return 0;
}
