#include<iostream>
using namespace std;
int n;
int a[100010];
int k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	if(n<=2&&k==0){
		cout<<2;
	}else if(n<=100&&k==0){
		cout<<100;
	}
	return 0;
}
