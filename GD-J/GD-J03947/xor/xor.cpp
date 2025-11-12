#include<bits/stdc++.h>
using namespace std;
int n,k,f=1;
int a[1111],d[1111][1111];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f && k==0) cout<<n/2;
	return 0;
}
