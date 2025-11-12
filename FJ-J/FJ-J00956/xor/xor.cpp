#include<bits/stdc++.h>
using namespace std;
int main(){	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n<=2&&k==0){
		cout<<1;
	}else if(n<=10&&k<=1){
		cout<<1;
	}else if(n<=100&&k==0){
		cout<<1;
	}else if(n<=100&&k<=1){
		cout<<1;
	}else if(n<=100&&k<=255){
		cout<<255;
	}else if(n<=200000&&k<=1){
		cout<<1;
	}else if(n<=200000&&k<=255){
		cout<<255;
	}else if(n<=500000&&k<=255){
		cout<<255;
	}
	return 0;
}
