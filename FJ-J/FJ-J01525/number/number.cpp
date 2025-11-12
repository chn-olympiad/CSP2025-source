#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int sum=0;
	cin>>s;
	for(int i=0; i<s.length(); i++) {
		if(s[i]>='0'&&s[i]<='9')a[sum++]=s[i]-'0';
	}
	sort(a,a+sum,cmp);
	for(int i=0; i<sum; i++)cout<<a[i];
	return 0;
}
