//AC
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N], cnt;
string s;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++){
		if (s[i] >= '0' && s[i] <= '9')
			a[++cnt] = s[i] - '0';
		else continue;
	}
	sort(a + 1, a + 1 + cnt, cmp);
	for (int i = 1; i <= cnt; i++)
		cout << a[i];
	return 0;
}