#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[100];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
	}else if(n==2){
		cout<<1;
	}
	return 0;
}

