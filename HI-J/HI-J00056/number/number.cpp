#include "bits/stdc++.h"
using namespace std;
int a[1000100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n,k=0,i;
	cin>>s;
	n=s.size();
	if(n==1){
		cout<<s[0];
		return 0;
	}
	for(i=0;i<n;i++){
		if(isdigit(s[i]))a[k++]=s[i]-'0';
	}
	sort(a,a+k);
	for(i=k-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
