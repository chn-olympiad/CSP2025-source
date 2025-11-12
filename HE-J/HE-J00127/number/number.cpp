#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];
bool cmp(int x, int y) {
	if(x > y) return true;
	else return false;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int j = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= '0' and s[i] <= '9') {
			a[j] = s[i]-'0';
			j++;
		}
	}
	sort(a, a+j, cmp);
	string ans = "";
	for(int i = 0; i < j; i++) {
		ans += a[i]+'0';
	}
	cout << ans;
	
	return 0;
}
//#Shang4Shan3Ruo6Shui4
