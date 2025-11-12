#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n==1 && a[1]!=k){
		cout<<0;
	}else if(n==1 && a[1]==k){
		cout<<1;
	}else if(n==2 && k==0 && a[1]==a[2]){
		cout<<1;
	}else if(n==2 && k==1 && a[1]!=a[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 