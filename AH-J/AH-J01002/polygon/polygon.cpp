#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	if(a[1]+a[2]+a[3]>maxn*2){
		long long ans=0;
		for(int i=3;i<=n;i++){
			long long sum=1;
			for(int j=n-i+1;j<=n;j++){
				sum=(sum%998244353)*(j%998244353)%998244353;
			}
			for(int j=1;j<=i;j++) sum=sum/j;
			ans=ans+sum;
		}
		cout<<ans;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*maxn) cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
