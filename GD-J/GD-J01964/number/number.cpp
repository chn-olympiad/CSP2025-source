#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	
	if(s.size() <= 1) {
		cout << s[0] << endl;
		return 0;
	}
	
	int n = 0;
	for(int i=0; i<s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[n] = s[i] - '0';
			n++;
		}
	}
	cout << n << endl;
	sort(a, a+n, cmp);
	for(int i=0; i<n; i++) {
		cout << a[i];
	}
	cout << endl;
	return 0;
}
