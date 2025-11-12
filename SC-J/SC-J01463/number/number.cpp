#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e6 + 5;
int num[15];
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for(int i = 0; i <= 10; i++) num[i] = 0;
	string s;
	cin >> s;
	s = " " + s;
	for(int i = 1; i < s.size(); i++) 
		if(s[i] >= '0' && s[i] <= '9') 
			num[s[i] - '0']++;
	for(int i = 9; i >= 0; i--) {
		while(num[i]--) {
			cout << i;
		}
	}
	cout << endl;
	return 0;
}