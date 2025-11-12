#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	string s; 
	getline(cin,s);
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 