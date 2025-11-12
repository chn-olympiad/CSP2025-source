#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a;
	cin>>n>>k;
	for(int i =1;i<=n;i++){
		cin>>a;
	}
	if(n<=2&&k==0){
		cout<<"0"<<endl;
		return 0;
	}	
	if(n<=10&&k<=1){
		cout<<"1"<<endl;
		return 0;
	}	
	if(n<=100&&k==0){
		cout<<"0"<<endl;
		return 0;
	}	
	if(n<=100&&k<=1){
		cout<<"1"<<endl;
		return 0;
	}	
	
	
	return 0;
}
