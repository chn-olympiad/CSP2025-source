#include<bits/stdc++.h>
using namespace std;
int b1,b2,b3,b4,b5,b6,b7,b8,b9,b;
char a[1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s=0;
	for(int i=1;i<=1;i++){
		cin>>a[i];
		s=a[i];
		if(s>=48&&s<=57){
			if(s==57){
				b1=9;
				cout<<b1;
			}
			if(s==56){
				b2=8;
				cout<<b2;
		    }
			if(s==55){
				b3=7;
				cout<<b3;
		    }
			if(s==54){
				b4=6;
				cout<<b4;
			}
			if(s==53){
				b5=5;
				cout<<b5;
			}
			if(s==52){
				b6=4;
				cout<<b6;
			}
			if(s==51){
				b7=3;
				cout<<b7;
			}
			if(s==50){
				b8=2;
				cout<<b8;
			}
			if(s==49){
				b9=1;
				cout<<b9;
		    }
			if(s==48){
				b=0;
				cout<<b;
			}
		} 
	}
	
	return 0;
}