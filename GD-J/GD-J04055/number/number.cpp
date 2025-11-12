#include <bits/stdc++.h>
using namespace std;
string s;
int a[15];
bool vis;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[s[i]- '0']++;
		}
	}
	for(int i = 9; i >= 0; i--) {
		if(i > 0) {
			vis = true;
			for(int j = 1; j <= a[i]; j++) {
				cout << i;
			}
		} else if(i == 0) {
			if(vis == false) {
				cout << 0;
			} else {
				for(int j = 1; j <= a[i]; j++) {
					cout << i;
				}
			}
		}
	}
	return 0;
}
