#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10],b;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	b=s.size();
	for(int i=0; i<b; ++i) {
		if(s[i]>='0'&&s[i]<='9') {
			++a[s[i]-48];
		}
	}
	for(int j=9; j>=0; j--) {
		for(int i=1; i<=a[j]; ++i) {
			cout<<j;
		}
	}
	return 0;
}