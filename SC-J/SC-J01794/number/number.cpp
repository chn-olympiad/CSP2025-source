#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,a[1000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.length(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[cnt++]=s[i]-'0';
		}
	}
	sort(a,a+cnt);
	reverse(a,a+cnt);
	for(int i=0; i<cnt; i++) {
		cout<<a[i];
	}
	return 0;
}