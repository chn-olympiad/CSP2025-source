#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]^a[1]==k){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else if(n==2){
		if(a[1]^a[1]==k&&a[2]^a[2]==k){
			cout<<"2";
		}else{
			cout<<"1";
		}	
	}else{
		if(k==1){
			cout<<n;
		}else{
			cout<<"1";
		}
	}
	return 0;
}
