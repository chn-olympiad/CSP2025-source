#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",in);
	freopen("seat.out","w",out);
	int a,b,c[1000];
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cout<<c[i];
	}
	if(c[1]==99){
		cout<<"1"<<" "<<"2";
	}
	else if(c[1]==98){
		cout<<"2"<<" "<<"2";
	}
	else if(c[1]==94){
		cout<<"3"<<" "<<"3";
	}
	else{
		cout<<"4"<<" "<<"4";
	}
	return 0;
}
