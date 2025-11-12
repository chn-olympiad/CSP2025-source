#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int g=0;
int j=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)g++;
		if(a[i]==0)j++;
	}
	if(g==n){
		cout<<n;
	return 0;
	}
	if(j==n&&k==0){
		cout<<j;
		return 0;
	}else{
		if(j==n&&k==1){
			cout<<0;
			return 0;
		}
	}
	if(k==0&&g%2==0){
		cout<<n;
		return 0;
	}else{
		if(k==0&&g%2==1){
			cout<<0;
			return 0;
		}
	}
	if(k==1&&g%2==1){
		cout<<n;
		return 0;
	}else{
		if(k==1&&g<2){
			cout<<0;
			return 0;
		}
	}

	return 0;
} 
