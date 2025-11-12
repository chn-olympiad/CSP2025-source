#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a[10]={0},x=0,b=0;
	string s;
	cin >> s;
	x=s.size();
	for(int i=0;i<x;i++) {
		if(s[i]<='9' && s[i]>='0') {
			b=s[i]-48;
		   	++a[b];
		}
	}
	for(int i=9;i>=0;i--) {
	     for(int y=a[i];y>0;y--) {
	      	 cout << i;
		 }
	}
	return 0;
} 
