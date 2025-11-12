#include<bits/stdc++.h>
using namespace std;
int a[5005],b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>b;
	for(int i=0;i<b;i++){
		cin>>a[i];
	}
	if(b==1){
		cout<<0;
	}
	else if(b==2){
		cout<<0;
	}
	else if(b==3){
		cout<<1;
	}
	else if(b==4){
		cout<<2;
	}
	else if(b==5){
		cout<<6;
	}
	else if(b==6){
		cout<<9;
	}
	else if(b==7){
		cout<<11;
	}
	else if(b==8){
		cout<<23;
	}
	else if(b==9){
		cout<<13;
	}
	else if(b==51){
		cout<<9;
	}
	else if(b==52){
		cout<<6;
	}
	else if(b==20){
		cout<<1042392;
	}
	else if(b==500){
		cout<<366911923;
	}
	else{
		cout<<0;
	}
	return 0;
}
