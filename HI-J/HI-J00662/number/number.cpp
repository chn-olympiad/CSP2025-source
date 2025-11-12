#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string s;
int a[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for (int i=0; i<s.size(); i++) {
		int n = s[i]-'0';
		if (n >=0 && n<=9) {
			a[n]++;
		}
	}
	for (int i=9; i>=0; i--) {
		for (int j=1; j<=a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}



