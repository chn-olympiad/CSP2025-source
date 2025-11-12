#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
char s[1000010];
int a[1000010];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> (s + 1);
	int t = 1, maxa = -1, pos;
	for (int i = 1; s[i] != '\0'; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[t++] = s[i] - '0';
		}
	}
	for (int i = 1; i < t; i++) {
		maxa = -1;
		for (int j = 1; j < t; j++) {
			if (a[j] > maxa) maxa = a[j], pos = j; 
		}
		a[pos] = -1;
		cout << maxa;
	}
	
	
	
	
	
	
	
	
	
	return 0;
} 
