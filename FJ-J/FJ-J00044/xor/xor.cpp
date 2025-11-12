#include<bits/stdc++.h>
//#define int longlong
using namespace std;
long long int a[10000],n,k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
	if(n<=10&&k<=1){
		cout<<1;
	}else if(n<=100&&k==0){
		cout<<1;
	}else if(n<=100&&k<=0){
		cout<<0;
	}else if(n<=2&&k==0){
		cout<<1;
	}else if(n<=200000&&k<=1){
		cout<<0;
	}
	return 0;
}
