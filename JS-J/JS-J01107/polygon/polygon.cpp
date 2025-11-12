#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5005],b[5005],c[5005][5005];
int main(){	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		c[i][0]=1;
		c[i][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	for(int i=3;i<=n;i++){
		ans=(ans+c[n][i])%998244353;
	}
	cout<<ans;
	return 0;
}
