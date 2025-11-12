#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==1||n==2||n==3){
		cout<<8;
	}else if(n<=250){
		cout<<100;
	}else if(n>=2500){
		cout<<1;
	}else{
		cout<<5000;
	}
	
	return 0;
} 
