#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[1000001];
	int len=s.size();
	for(int i=1;i<=len;i++) {
		if(s[i]>='1' && s[i]<='9') {
			a[i]=s[i];
		}
	}
	sort(a+1,a+1+len);
	for(int i=1;i<=len;i++) {
		cout<<a[i];
	}
	return 0;
}

