#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sc=s.size(),sz=0;
	for(int i=0; i<sc; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[sz++]=s[i]-'0';
		}
	}
	sort(a,a+sz);
	for(int i=sz-1; i>=0; i--) {
		cout<<a[i];
	}
	return 0;
}