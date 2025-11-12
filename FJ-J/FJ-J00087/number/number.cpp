//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string s;
int a[10];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0; i<s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[s[i]-'0']++;
		}
	}
	if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0&&a[7]==0&&a[8]==0&&a[9]==0) {
		printf("0");
		return 0;
	}
	for(int i=9; i>=0; i--) {
		if(a[i] != 0) {
			for(int j=1; j<=a[i]; j++) {
				printf("%d",i);
			}
		}
	}
	return 0;
}

