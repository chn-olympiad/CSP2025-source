#include<bits/stdc++.h>
using namespace std;
long long a,b[5001],m=0;
void A1(){
	if(b[1]+b[2]>b[3]&&b[1]-b[2]<b[3]){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i];
	}
	for(int i=1;i<=a;i++){
		
	}
    if(a<=3) A1();
}
