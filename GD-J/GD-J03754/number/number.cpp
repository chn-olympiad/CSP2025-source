#include <bits/stdc++.h>
using namespace std;
int s[1145145];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	string str;
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, str);
	long long cnt = 0;
	for(long long i = 0;i < str.length();i ++) {
		if('0' <= str[i] && str[i] <= '9') {
			s[++cnt] = str[i] - '0';
		}
	}
	sort(s + 1, s + cnt + 1, cmp);
	for(int i = 1;i <= cnt;i ++) {
		printf("%d", s[i]);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
