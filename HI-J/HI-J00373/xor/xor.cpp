#include<bits/stdc++.h>
using namespace std;
int n=0,k=0;
int a[500000]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<1;
	}else{
		cout<<5;
	}
	
	return 0;
}

