#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	char a[n];
	int b[n],s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(b[i]!=0){
			s++;
		}
	}
	cout<<s%998%244%353;
	return 0;
}
