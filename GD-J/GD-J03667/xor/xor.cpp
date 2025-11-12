#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int main() {
	
	freopen("xor.in", "r", stdin);
	freopen("xor.ans", "w", stdout);
	
	int n, ans=0;
	ull k;
	vector<int> q;
	cin >> n >> k;
	vector<ull> v(n);
	for (int i=0;i<n;++i) {
		cin >> v[i];
	}
	for (int i=0;i<n;++i) {
		if (v[i] == k) {
//			cout << i << ' ' << q.size();
//			if (q.size() == 0) cout << ' ' << v[i];
//			cout << endl;
			
			ans++;
			q.clear();
			continue;
		} else {
			for (int j=0;j<q.size();++j) {
				if ((q[j]^v[i]) == k) {
//					cout << i << ' ' << q.size();
//					cout << endl;
					ans++;
					q.clear();
					continue;
				}
			}
		}
		q.push_back(v[i]);
	}
	cout << ans;
	
	return 0;
} 
