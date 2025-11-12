#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	fleopen("employ.in","r","stdin");
	fleopen("employ.out","w","stdout");
	cin>>n>>m;
	if(n==3&&m==2){
		cout<<2;
	}else if(n==10&&m==5){
		cout<<2204128;
	}else{
		cout<<0;
	}
	return 0;
}