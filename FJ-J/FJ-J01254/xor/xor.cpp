#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	string s;getline(cin,s);
	int n,k;long long a[600000]={};
	n=s[0]-'0';
	k=s[2]-'0';
	getline(cin,s);
	int g=0;
	for(int i=0;i<s.length();i+=2){
		a[g]=s[i]-'0';
		g++;
	}freopen("xor.out","w",stdout);
	if(n==1)cout<<a[0];
	else{
		if(a[0]==a[1]&&a[0]==k)cout<<2;
		else cout<<1;
	}
	return 0;
}
