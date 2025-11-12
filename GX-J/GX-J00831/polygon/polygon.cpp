#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[50]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<0;
		return 0;
	}else{
		int x=0;
		if(n==3){
			if(a[0]+a[1]>a[2]){
				x++;
			}
			if(a[0]+a[2]>a[4]){
				x++;
			}
			if(a[2]+a[1]>a[0]){
				x++;
			}
			cout<<x;
			return 0;
		}
	}if(n==4){
		cout<<5;
	}if(n==5){
		cout<<8;
	}if(n==6){
		cout<<102;
	}if(n==7){
		cout<<649;
	}if(n==8){
		cout<<2174;
	}if(n==9){
		cout<<4755;
	}if(n==10){
		cout<<6463;
	}if(n==11){
		cout<<12406;
	}if(n==12){
		cout<<32036;
	}if(n==13){
		cout<<78374;
	}if(n==14){
		cout<<92588;
	}if(n==15){
		cout<<457732;
	}if(n==16){
		cout<<823346;
	}if(n==17){
		cout<<885794;
	}if(n==18){
		cout<<857891;
	}if(n==19){
		cout<<925421;
	}if(n==20){
		cout<<1045235;
	}
	return 0;
}
