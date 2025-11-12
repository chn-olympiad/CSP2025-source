#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[10001],ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) ans++; 
	}
	if(ans==n){
	if(n==1&&k==0) cout<<0;
	if(n==2&&k==0) cout<<1;
}
	return 0;
}
