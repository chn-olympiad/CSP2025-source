#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b1,b2,b3,b4,b5,b6,b7,b8,b9,b0,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<1000001;i++){
		a[i]=getchar();
		if(a[i]==32||a[i]==10){
			n=i-1;
			break;
		}
		if(48==a[i]){
			b0++;
		}
		if(49==a[i]){
			b1++;
		}
		if(50==a[i]){
			b2++;
		}
		if(51==a[i]){
			b3++;
		}
		if(52==a[i]){
			b4++;
		}
		if(53==a[i]){
			b5++;
		}
		if(54==a[i]){
			b6++;
		}
		if(55==a[i]){
			b7++;
		}
		if(56==a[i]){
			b8++;
		}
		if(57==a[i]){
			cout<<a[i];
		}
	}
	for(int i=1;i<=b8;i++){
		cout<<8;
	}
	for(int i=1;i<=b7;i++){
		cout<<7;
	}
	for(int i=1;i<=b6;i++){
		cout<<6;
	}
	for(int i=1;i<=b5;i++){
		cout<<5;
	}
	for(int i=1;i<=b4;i++){
		cout<<4;
	}
	for(int i=1;i<=b3;i++){
		cout<<3;
	}
	for(int i=1;i<=b2;i++){
		cout<<2;
	}
	for(int i=1;i<=b1;i++){
		cout<<1;
	}
	for(int i=1;i<=b0;i++){
		cout<<0;
	}
	return 0;
} 
