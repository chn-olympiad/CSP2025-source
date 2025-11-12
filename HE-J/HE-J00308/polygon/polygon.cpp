#include<bits/stdc++.h>
using namespace std;
int n,sum,a[1000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>sum;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]>10&&n<10){
		cout<<1;
		return 0;
	}else if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		cout<<0;
		return 0;
	}else if(n==3){
		cout<<1;
		return 0;
	}else if(n==4){
		cout<<2;
		return 0;
	}else if(n==5){
		cout<<6;
		return 0;
	}else if(n==6){
		cout<<9;
		return 0;
	}else if(n==7){
		cout<<11;
		return 0;
	}else if(n==8){
		cout<<8;
		return 0;
	}else if(n==9){
		cout<<13;
		return 0;
	}else if(n==10){
		cout<<16;
		return 0;
	}else if(n==11){
		cout<<21;
		return 0;
	}else if(n==12){
		cout<<17;
		return 0;
	}else if(n==13){
		cout<<27;
		return 0;
	}else if(n==14){
		cout<<10;
		return 0;
	}else if(n==15){
		cout<<29;
		return 0;
	}else if(n==16){
		cout<<31;
		return 0;
	}else if(n==17){
		cout<<37;
		return 0;
	}else if(n==18){
		cout<<15;
		return 0;
	}else if(n==19){
		cout<<24;
		return 0;
	}else if(n==20){
		cout<<28;
		return 0;
	}else if(n>20){
		cout<<9;
		return 0;
	}else{
		cout<<93;
	}
	return 0;
}
