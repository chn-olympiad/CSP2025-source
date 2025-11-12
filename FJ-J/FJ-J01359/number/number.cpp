#include<bits/stdc++.h>
using namespace std;
int a[110];
int h[110];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[s[i]-'0']++;
			h[s[i]-'0']++;
		}
	}
	for(int i=9; i>=0; i--) {
		for(int j=1; j<=h[i]; j++) {
			cout<<i;
		}
	}
	return 0;
}
