#include <cstdio>
#include <cstring> 
#include <iostream>
#include <algorithm>
#define isnumber(a) a >= '0' && a <= '9'
using namespace std;
bool cmp(int, int);
char str[1000005];
int number[1000005];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int tnumber = 0;
	cin >> str;
	int length = strlen(str);
	for (int i = 0; i < length; i++) {
		if (isnumber(str[i])) {
			number[tnumber++] = str[i] - '0';
		}
	}
	sort(number, number + tnumber, cmp);
	for (int i = 0; i < tnumber; i++) {
		cout << number[i];
	}
	return 0;
}
bool cmp(int a, int b) {
	return a > b;
}
// 100 pts
