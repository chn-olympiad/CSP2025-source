#include <iostream>
#include <vector>
using namespace std;

int solve(string a, string b, string c, string d) {
	int size = b.size();
	for (int i=0;i<a.size();i++) {
		bool flag = 1;
		int pos;
		for (int j=0;j<size;j++) {
			if (a[i+j] != b[j]) {
				flag = 0;
				break;
			} else {
				pos = i+j;
			}
		}
		if (!flag)
			continue;
		pos -= size - 1;
		for (int k=0;k<a.size();k++) {
			
			if (pos<=k&&k<pos+size) {
//				cout << "enter: " << pos << k << d[k] << ' ';
				if (c[k-pos] != d[k]) {
					flag = 0;
					break;
				}
			} else {
				if (a[k] != d[k]) {
					flag = 0;
					break;
				}
			}
		}
		if (!flag) {
			continue;
		} else {
			return 1;
		}
	}
	return 0;
}

int main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	cin.tie(0);
	cout.tie(0);
	
	long long n, q;
	cin >> n >> q;
	vector<pair<string, string>> mp(n);
	for (int i=0;i<n;++i) {
		string s1, s2;
		cin >> s1 >> s2;
		mp[i] = {s1, s2};
	}
	for (long long i=0;i<q;++i) {
		long long ans = 0;
		string s0, s3;
		cin >> s0 >> s3;
		for (pair<string, string> s: mp) {
			string s1 = s.first, s2 = s.second;
			ans += solve(s0, s1, s2, s3);
		}
		cout << ans << '\n';
	}
	
	
	return 0;
}
