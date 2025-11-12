#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
string s,a;
int len,lena;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0; i<len; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a+=s[i];
		}
	}
	sort(a.begin(),a.end());
	lena=a.size();
	for(int i=lena-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

