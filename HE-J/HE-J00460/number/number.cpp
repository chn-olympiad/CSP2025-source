#include<bits/stdc++.h>
using namespace std;
string s,x;
long long i=1,j=1,g=0,f=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	g=s.length();		
	for(int k=1;k<=g;k++){
		if(s[k]>='0'&&s[k]<='9'){
			x[j]+=s[k];
			j++;
		}
	}
	f=x.length();
	for(int k=1;k<=f;k++){
		for(int l=k+1;l<=f;l++){
			if(x[k]<x[l])swap(x[k],x[l]);
		}
	}
	cout<<x;
	return 0;
} 
