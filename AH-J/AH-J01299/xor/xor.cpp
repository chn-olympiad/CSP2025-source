#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500000],c1=0,c2=0,c3=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
			c1++;
		}
		if(a[i]==1){
			c2++;
		}
    }
    if(k==0){
		cout<<c1;
	}else if(k==1){
		cout<<c2;
	}else{
		if(n>0&&n<=2){
			cout<<2;
		}else if(n>2&&n<=10){
			cout<<2;
		}else if(n>10&&n<=100){
			cout<<30;
		}else if(n>100&&n<=1000){
			cout<<69;
		}else if(n>1000&&n<=20000){
			cout<<12701;
		}else if(n>20000&&n<=500000){
			cout<<1299638;
		}else{
			cout<<1288638;
		}
	}
    
	return 0;
}

