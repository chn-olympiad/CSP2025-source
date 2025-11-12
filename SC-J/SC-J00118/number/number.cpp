#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string s;
int c[1000005];
int num = 0;
bool cmp(int x, int y) {
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] >= '0' && s[i] <= '9') {
			c[++num] = s[i] - '0';
		}
	}
	sort(c + 1, c + num + 1, cmp);
	for(int i = 1; i <= num; ++i) {
		cout << c[i];
	}
	return 0;
} 