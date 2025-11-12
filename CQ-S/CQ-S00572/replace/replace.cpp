#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<string, string> > v;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		string a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	while(q--) {
		string a, b;
		cin >> a >> b;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int j = 0, k = 0, l, r;
			bool f = 0;
			while(j < a.size() && k < v[i].first.size()) {
				if (a[j] == v[i].first[k]) {
					f = 1;
					l = j;
					while(a[j] == v[i].first[k] && j < a.size() && k < v[i].first.size()) {
						j++;
						k++;
					}
					if (k == v[i].first.size()) {
						r = j;
					}
					else {
						f = 0;
					}
					break;
				}
				else {
					j++;
				}
			}
			if (f == 1) {
				bool fl = 1;
				for (int j = l, k = 0; j < r, k < v[i].second.size(); j++, k++) {
					if (b[j] != v[i].second[k]) {
						fl = 0;
						break;
					}
				}
				if (fl == 1) {
					for (int j = 0; j < l; j++) {
						if (a[j] != b[j]) {
							f = 0;
							break;
						}
					}
					if (f == 1) {
						for (int j = r; j < a.size(); j++) {
							if (a[j] != b[j]) {
								fl = 0;
								break;
							}
						}
						if (fl == 1) {
							sum++;
						}
					}
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
