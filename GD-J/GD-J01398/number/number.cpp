#include <bits/stdc++.h>
using namespace std;
int a[1000000],b=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9') a[b++]=s[i]-'0';
	}
	sort(a,a+b);
	for(int i=0;i<b;i++){
		cout<<a[b-i-1];
	}
	return 0; 
}
