#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c0=0,c1=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0)c0++;
		if(a[i]==1)c1++;
	}
	if(c0==n)cout<<n/2;
	else if(k==1)cout<<c1;
	else cout<<(c0+c1/2+n/2)%n;
	
	return 0;
}
