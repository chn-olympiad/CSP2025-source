#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int tmp=1;
	for(int i=0; i<s.size(); i++) {
		if(isdigit(s[i])) {
			a[tmp++]=s[i]-'0';
		}
	}
	sort(a,a+tmp);
	for(int i=tmp-1; i>=1; i--)cout<<a[i];
	return 0;
}                                                                         