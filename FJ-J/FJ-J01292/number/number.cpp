#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000+5];
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	int j=1;
	int i;
	for(i=0;i<l;i++) {
		if('0'<=s[i] and s[i]<='9') {
			a[j]=int(s[i]-'0');
			j++;
		}
	}
	sort(a+1,a+j);
	for(i=j-1;i>=1;i--) {
		cout<<a[i];
	}
	return 0;
}