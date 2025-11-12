#include<bits/stdc++.h>
using namespace std;
int num[1000005], i;
string s;
int main() {
	freopen("number3.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int j = 0; j <= s.length() - 1; j ++) {
		if(s[j] >= '0' && s[j] <= '9') {
			num[i] = -(s[j] - '0');
			i ++;
		}
	}
	sort(num, num + i);
	for(int j = 0; j < i; j ++) {
		cout << -num[j];
	}
	return 0;
}
