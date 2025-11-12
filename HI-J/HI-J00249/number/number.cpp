#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	
	for(int i=9;i>=0;i--){
		
		for(int j=0;j<=a.size();j++){
			if(i==9){
				char n='9';
				if(a[j]==n){
					cout<<"9";
				}
			}else if(i==8){
				char n='8';
				if(a[j]==n){
					cout<<"8";
				}
			}else if(i==7){
				char n='7';
				if(a[j]==n){
					cout<<"7";
				}
			}else if(i==6){
				char n='6';
				if(a[j]==n){
					cout<<"6";
				}
			}else if(i==5){
				char n='5';
				if(a[j]==n){
					cout<<"5";
				}
			}else if(i==4){
				char n='4';
				if(a[j]==n){
					cout<<"4";
				}
			}else if(i==3){
				char n='3';
				if(a[j]==n){
					cout<<"3";
				}
			}else if(i==2){
				char n='2';
				if(a[j]==n){
					cout<<"2";
				}
			}else if(i==1){
				char n='1';
				if(a[j]==n){
					cout<<"1";
				}
			}else if(i==0){
				char n='0';
				if(a[j]==n){
					cout<<"0";
				}
			}
		}
	}
	return 0;
}

