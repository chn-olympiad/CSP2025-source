#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	for(int i=0; i<=9; i++) a[i]=0;
	for(int i=0; i<s.size(); i++) {
		if('0'<=s[i]&&s[i]<='9') {
			int st=(int)s[i]-'0';
			a[st]++;
		}
	}
	for(int i=9; i>=0; i--) {
		while(a[i]) {
			cout<<i;
			a[i]--;
		} 
	}
	return 0;
}
