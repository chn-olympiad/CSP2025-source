#include<bits/stdc++.h>
using namespace std;
int a[150],su;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9'){
		a[s[i]-'0']++;
		su++;
	}
	for(int i=9;i>=1;i--){
		for(;a[i];a[i]--) printf("%d",i); 
	}
	if(su!=a[0]) for(;a[0];a[0]--) putchar('0');
	else putchar('0');
	return 0;
}
