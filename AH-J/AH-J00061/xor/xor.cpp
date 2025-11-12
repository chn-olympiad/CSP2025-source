#include <bits/stdc++.h>
using namespace std;
string totwo(int a){
	string s="";
	while(a){
		if(a%2!=0)
			s+="1";
		else
			s+="0";
		a/=2;
	}
	return s;
}
int toten(string s){
	int a=0;
	for(int i=s.length()-1;i>=0;i--)
		a+=(s[i]-48)*pow(2,s.length()-1-i);
	return a;
}
int main(){
	int n,k;
	freopen("xor.in","r",stdin);
	cin>>n>>k;
	return 0;
}
