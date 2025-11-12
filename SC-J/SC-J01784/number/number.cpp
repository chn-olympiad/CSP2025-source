#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
bool cmp(long long x, long long y) {
	return x > y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	long long cnt = 1;
	long long n = s.size();
	for (long long i = 0; i < n; i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[cnt] = s[i] - '0';
			cnt ++;
		}
	}
	cnt --;
	sort(a + 1, a + 1 + cnt, cmp);
	if (a[1] == 0) {
		cout << 0 << '\n';
		return 0;
	}
	for (long long i = 1; i <= cnt; i ++) {
		cout << a[i];
	}
	return 0;
}