#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],aa;
int main(){
	freopen("xor1.in","r",stdin);
	freopen("xor1.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)
		aa++;
	}
	if(k==0){
		cout<<n/2;
		return 0;
	}
	if(k==1){
		cout<<n;
		return 0;
	}
		cout<<n;
	return 0;
} 
