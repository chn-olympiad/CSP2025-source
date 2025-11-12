#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	int a[10]={};
	for (int i=0;i<n;i++){
		if (s[i]>='0' && s[i]<='9'){
			int m=s[i]-'0';
			//printf("%d %d\n",m,s[i]);
			a[m]++;
		}
	}
	for (int i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	return 0;
}
