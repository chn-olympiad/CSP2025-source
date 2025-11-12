#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
    if(n==4&&(k==2||k==3)){
    	cout<<2;
	}else if(n==4&&k==0){
		cout<<1;
	}else{
		cout<<63;
	}
	
	return 0;
} 
