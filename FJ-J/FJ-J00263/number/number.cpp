#include<bits/stdc++.h>
using namespace std;
string s;
long long t[12];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0; i<=s.size()-1; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			t[s[i]-'0']++;
		}
	}
	for(long long i=9; i>=0; i--) {
		for(long long j=1; j<=t[i]; j++) {
			putchar(i+48);
		}
	}
	return 0;
}
