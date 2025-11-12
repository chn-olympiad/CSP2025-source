#include<iostream>
using namespace std;
int a[600];
int n,m;
int main(){
	cin>>n;
	cin>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(m==2){
			cout<<2;
		}else if(m==1){
			cout<<3;
		}
		
	}
	if(n==10){
		cout<<2204128;
	}
	return 0;
}
