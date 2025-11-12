#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;
char a[100000],t;
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,n);
	long long k=n.size();
	for(long long i=0;i<k;i++)
		if((n[i]>='1'&&n[i]<='9')||n[i]=='0')a[i]=n[i];
	for(long long j=1;j<=k;j++){
		for(long long i=0;i<k;i++){
			if(a[i]<a[i+1]){
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
			}
		}
	}
	for(long long i=0;i<k;i++)cout<<a[i];
	return 0;
}
