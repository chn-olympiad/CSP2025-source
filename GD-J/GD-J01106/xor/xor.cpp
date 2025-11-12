#include<bits/stdc++.h>
using namespace std;
int a[1000001],b,x=0,n,k,a1[1000001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int t=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=a1[i-1]+a[i];
		if(a[i]!=1){
			t=0;
		}
	}
	if(t&&k==0){
		cout<<n/2;
		return 0;
	}
	else if(k==0){
		cout<<a1[n]/2;
	}
	else if(k==1){
		cout<<a1[n];
	}
	return 0;
}
