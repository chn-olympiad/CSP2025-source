#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
string s;
int a[N], cnt = 0;
bool cmp(int x, int y) {
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i ++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[++ cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	for(int i = 1; i <= cnt; i ++) {
		printf("%d", a[i]);
	}
	return 0;
}
