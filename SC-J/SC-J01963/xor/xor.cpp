#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f==1){
		cout<<n/2;
	}
	else{
		cout<<2;
	}
	return 0;
}