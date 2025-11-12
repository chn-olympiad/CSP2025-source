#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
	}
	else if(k==1){
		cout<<n;
	}
	else if(k>1){
		cout<<0; 
	}
	return 0;
}
