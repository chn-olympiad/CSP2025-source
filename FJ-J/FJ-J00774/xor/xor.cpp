#include<bits/stdc++.h>
using namespace std;
int a[5*100000+5],b000=0,n,k,b001=0;
bool A111=1,B111=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			b000++;
		}
		if(a[i]==1){
			b001++;
		}
		if(a[i]!=1){
			A111=0;
		}
		if(a[i]!=0&&a[i]!=1) B111=0;
	}
	if(A111&&k==0){
		cout<<n/2;
	}else if(B111&&k<=1){
		if(k=0){
			cout<<b001/2+b000;
		}
		if(k=1){
			cout<<b001;
		}
	}
	return 0;
}
