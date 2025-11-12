#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fs first
#define sc second
bool cmp(pair<int, int> x, pair<int, int> y) {
//	if(x.sc - x.fs + 1 != y.sc - y.fs + 1) return (x.sc - x.fs + 1) < (y.sc - y.fs + 1);
//	else return x.sc < y.sc;
	if(x.sc != y.sc) return x.sc < y.sc;
	else return (x.sc - x.fs + 1) < (y.sc - y.fs + 1);
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
//		cout << 1 << "\n";
	vector <int> a(n + 10), pre(n + 10, 0), mp(1 << 21, 0);
	vector <pair<int,int>> line; 
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
		if((pre[i] ^ k) == 0) {
//			cout << "_______________1________________" << pre[i] << " " << (pre[i] ^ k) << "\n";
			line.emplace_back(make_pair(mp[pre[i] ^ k] + 1, i));
			mp[pre[i]] = i;
			continue;
		}
		if(mp[pre[i] ^ k] != 0) line.emplace_back(make_pair(mp[pre[i] ^ k] + 1, i));
		mp[pre[i]] = i;
	}
//	cout << 1 << "\n";
	sort(line.begin(), line.end(), cmp);
	vector <int> f(n + 10, 0);
	int ans = 0;
	for(int i = 0;i < line.size();i++) {
//		cout << line[i].fs << " " << line[i].sc << "\n"; 
		bool mark = 0;
		for(int j = line[i].fs; j <= line[i].sc;j++)  {
			if(f[j] == 1) {
				mark = 1;
				break;
			}
		}
		if(mark == 1) continue;
		ans++;
		for(int j = line[i].fs; j <= line[i].sc;j++) {
			f[j] = 1;
		}
	}
	cout << ans << "\n";
	return 0;
}

