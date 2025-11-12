#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;
int cnt[10];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++) {
		if(s[i] >= '0' and s[i] <= '9') {
			int tmp = s[i] - '0';
			cnt[tmp]++;
		}
	}
	for(int i = 9;i >= 0;i--) {
		for(int j = 1;j <= cnt[i];j++) {
			cout << i;
		}
	}
	return 0;
} 
