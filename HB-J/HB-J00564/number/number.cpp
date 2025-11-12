#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string n;
int a[1000002],x=1;

int main(){
	cin>>n;
	for(int j=1;j<=n.size();j++){
		if(n[j]-48<10&&n[j]-48>=0){
			a[x++]=n[j]-48;
		}
	}
	sort(a+1,a+x);
	for(int i=x-1;i>0;i--){
		cout<<a[i];
	}
	return 0;
}
