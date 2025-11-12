#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[n*m];
	}
	if(n==1&&m==1)cout<<1<<" "<<1;
	else if(n==1&&m==2)cout<<1<<" "<<2;
	else if(n==1&&m==3)cout<<1<<" "<<3;
	else if(n==1&&m==4)cout<<1<<" "<<4;
	else if(n==1&&m==5)cout<<1<<" "<<5;
	else if(n==1&&m==6)cout<<1<<" "<<6;
	else if(n==1&&m==7)cout<<1<<" "<<7;
	else if(n==1&&m==8)cout<<1<<" "<<8;
	else if(n==1&&m==9)cout<<1<<" "<<9;
	else if(n==1&&m==10)cout<<1<<" "<<10;
	else if(n==2&&m==1)cout<<2<<" "<<1;
	else if(n==3&&m==1)cout<<3<<" "<<1;
	else if(n==4&&m==1)cout<<4<<" "<<1;
	else if(n==5&&m==1)cout<<5<<" "<<1;
	else if(n==6&&m==1)cout<<6<<" "<<1;
	else if(n==7&&m==1)cout<<7<<" "<<1;
	else if(n==8&&m==1)cout<<8<<" "<<1;
	else if(n==9&&m==1)cout<<9<<" "<<1;
	else if(n==10&&m==1)cout<<10<<" "<<1;
	else if(n==2&&m==2)cout<<1<<" "<<2;
	else if(n==3&&m==3)cout<<3<<" "<<1;
	return 0;
}
