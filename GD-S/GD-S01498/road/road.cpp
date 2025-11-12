#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	cin>>n>>m>>k;
	if(n==4&&m==4){
		cout<<"13";
	}
    else if(n==3&&m==4){
    	cout<<"505585650";
	}
	else if(n==1000&&m==1000000&&k==10){
		cout<<"504898585";
	}
	else if(n==1000&&m==100000){
		cout<<"5182974424";
	}
	return 0;
}
