#include<bits/stdc++.h>
using namespace std;
int numm[12];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int isnum;
	int n=s.size();
	for (int i=0;i<n;i++) {
		if (s[i]>='0'&&s[i]<='9') {
			isnum=s[i]-'0';
			numm[isnum]++;
		}
	}
	for (int i=9;i>=0;i--) {
		for (int j=1;j<=numm[i];j++) {
			cout << i;
		}
	}
	return 0;
}
