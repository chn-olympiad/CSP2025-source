#include<bits/stdc++.h>
using namespace std;
int a[120],m,n,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n*m;i++){
		if(a[1]<a[i]&&i!=1){
			num++;
		}
	}
	if(num==0){
		cout<<"1"<<" "<<"1";
	}else if(num==1){
		cout<<"1"<<" "<<"2";
	}else if(num==2){
		cout<<"1"<<" "<<"3";
	}else if(num==3){
		cout<<"1"<<" "<<"4";
	}else if(num==4){
		cout<<"1"<<" "<<"5";
	}else if(num==5){
		cout<<"1"<<" "<<"6";
	}else if(num==6){
		cout<<"1"<<" "<<"7";
	}else if(num==7){
		cout<<"1"<<" "<<"8";
	}else if(num==8){
		cout<<"1"<<" "<<"9";
	}else if(num==9){
		cout<<"1"<<" "<<"10";
	}else{
		cout<<"2"<<" "<<"1";
	}
} 
