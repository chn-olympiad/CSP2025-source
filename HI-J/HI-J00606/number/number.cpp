#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],b,c;
int main() {
	 freopen("number.in","r",stdin);
	 freopen("number.out","w",stdout);
	getline(cin,s);
	int len=s.size();
	for (int i=0; i<len; i++) {
		c=s[i];
		if(c==57) {
			a[b]=9;
			b++;
		}
		if(s[i]==56) {
			a[b]=8;
			b++;
		}
		if(s[i]==55) {
			a[b]=7;
			b++;
		}
		if(s[i]==54) {
			a[b]=6;
			b++;
		}
		if(s[i]==53) {
			a[b]=5;
			b++;
		}
		if(s[i]==52) {
			a[b]=4;
			b++;
		}
		if(s[i]==51) {
			a[b]=3;
			b++;
		}
		if(s[i]==50) {
			a[b]=2;
			b++;
		}
		if(s[i]==49) {
			a[b]=1;
			b++;
		}
		if(s[i]==48) {
			a[b]=0;
			b++;
		}
	}
	for (int i=9; i>=0; i--) {
		for (int j=0; j<b; j++) {
			if(a[j]==i) {
				cout << i;
			}
		}
	}
	return 0;
}
