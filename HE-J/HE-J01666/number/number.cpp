#include<bits/stdc++.h>
using namespace std;
int a[1000101];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n;
	n=s.size();
	int j=0;
	for(int i=0;i<n;i++) {
		if(s[i]-'0'>9||s[i]-'0'<0) continue;
		j++;
		a[j]=s[i]-'0';
	}
	sort(a+1,a+1+j);
	for(int i=j;i>=1;i--) {
		cout<<a[i];
	}
	return 0;
}
 
