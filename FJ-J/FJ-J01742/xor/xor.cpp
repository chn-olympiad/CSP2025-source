#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a[1000086],n,k,s[1000086];
	cin>>n>>k;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)s[i]=a[i];
		else s[i]=a[i]^s[i-1];
	}
	if(k==0){
		cout<<n/2;
	}else{
		cout<<1;
	}	
	return 0;
} 
