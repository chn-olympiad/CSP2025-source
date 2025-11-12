#include<bits/stdc++.h>
using namespace std;
int c[5001][5001],n,a[5001],mod=998244353,max1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
	}
	for(int i=0;i<=5000;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max1*2) cout<<1;
		else cout<<0;
	}
	cout<<0;
}
