#include<bits/stdc++.h>
using namespace std;
long long i,n,k,a[1000000],f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(f==0&&k==0)cout<<0;
	else if(k==0)cout<<1;
	else cout<<2;
}
