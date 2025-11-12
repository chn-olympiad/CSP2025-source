#include<bits/stdc++.h>
using namespace std;
#define LL long long
char num[1000020];
bool cmp(char a, char b) {
	return a > b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	LL cnt = 0;
	LL a1 = a.size();
	for (int i = 0; i < a1; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			num[cnt] = a[i];
			cnt++;
		}
	}
	sort(num, num + cnt, cmp);
	for (int i = 0; i < cnt; i++) {
		cout << num[i];
	}
	return 0;
}