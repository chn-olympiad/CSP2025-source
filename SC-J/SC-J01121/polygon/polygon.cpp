#include<bits/stdc++.h>
using namespace std;
int n,a[5010],sum[6010],ans,maxn;
const int mod=998244353;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	sum[0]=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
		for(int j=maxn+1;j>=0;j--){
			if(j>a[i]) ans=(ans+sum[j])%mod;
			sum[min(maxn+1,j+a[i])]=(sum[j]+sum[min(maxn+1,j+a[i])])%mod;
		}
	}
//	for(int j=0;j<=6000;j++)
//		cout<<sum[j]<<" ";
	cout<<ans%mod;
	return 0;
}
/*
5
2 2 3 8 10
*/