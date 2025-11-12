#include<bits/stdc++.h>
using namespace std;
const int MAX=1e7;
string s;
int n,i;
int a[MAX];
void check(char s,int i) {
		if(s>='0' and s<='9') {
			a[i]=s-'0';
			n++;
		}
}
int main() {
	cin.tie(0);
	cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	for(i=0; s[i]; i++) {
		check(s[i],i);
	}
	sort(a,a+n);
	for(i=n; i>=1; i--) {
		cout<<a[i];
	}
	return 0;
}
