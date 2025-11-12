#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int cnt[10];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	for(char i : s) {
		if(i<='9'&&i>='0') {
			cnt[i-'0'] ++;
		}
	}
	bool fst = true;
	for(int i=9; i>=0; i--) {
		int tmp = cnt[i];
		if(fst) {
			if(i==0) {
				cout << '0';
				break;
			} else if(tmp>0)fst = false;
		}
		for(int j=0; j<tmp; j++) {
			cout << i;
		}
	}
	cout << endl;
	return 0;
}

