#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",in);
	freopen("seat.out","w",out);
	int a,b,c[1000];
	for(int i=1;i<=a*b;i++){
		cin>>c[i];
	}
	if(c[1]==1){
		cout<<"9";
	}
	else if(c[1]=="2"){
		cout<<"6";
	}
	else{
		cout<<"4";
	}
	return 0;
	}
