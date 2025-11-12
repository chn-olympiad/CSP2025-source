#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string s;
int a[N], it;
bool cmp(int x, int y) {
	return x>y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i=0; i<s.size(); i++)
		if('0'<=s[i]&&s[i]<='9') a[++it] = int(s[i]-'0');
	sort(a+1, a+it+1, cmp);
	for(int i=1; i<=it; i++) cout << a[i];
	return 0;
} 
// 8:49 ok
