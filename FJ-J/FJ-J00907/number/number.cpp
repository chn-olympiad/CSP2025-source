#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int n[20];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; s[i]!='\0'; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			n[s[i]-'0']++;
		}
	}
	for(int i=9; i>=0; i--) {
		for(int j=0; j<n[i]; j++) {
			cout<<i;
		}
	}
	return 0;
}
