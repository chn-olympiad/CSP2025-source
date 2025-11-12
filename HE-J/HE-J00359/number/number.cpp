#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000];
	int o,k,t,p,c,l=0;
	l=1;

for(int i=0;;i++){
	cin>>s[i];
	p++;
	if(s[i]=='/n'){
		break;
	}
}
for(int i=0; i<p; i++) {
		if(s[i]>='0'&&s[i]<='9'&&o==0) {
			o=s[i];
			c++;
		} else if(s[i]>='0'&&s[i]<='9') {
			o=o+s[i]*10;
			c++;
		}
	}
	for(int i=0; i<c; i++) {
		if(t<=o) {
			t==o;
		}
		for(int j=c--; j>=0; j--) {
			l=l*10;
		}

		k=o%10*l;
		o=(o/10)+k;
	}
	cout<<t;

	return 0;
}
