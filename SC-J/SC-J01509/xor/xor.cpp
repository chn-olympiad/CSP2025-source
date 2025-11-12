#include<bits/stdc++.h>
using namespace std;
long long k,n,a[1000000],t=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)t=1;
	}
	if(k==0&&t==0)cout<<n;
	return 0;
}