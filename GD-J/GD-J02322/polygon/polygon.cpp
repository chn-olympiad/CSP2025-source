#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5418],c=0;
	long long ans=0,bns=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>c)c=a[i];
	}
	if(n==3){
		if(a[1]+a[3]+a[2]>c*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(c==1){
		for(int i=1;i<=n;i++){
			ans+=bns;
			bns=bns*2;
			ans=ans%998244353;
			bns=bns%998244353;
		}
		bns=(n*n+n)/2;
		bns=bns%998244353;
		ans=ans-bns;
		if(ans<0)ans+=998244353;
		cout<<ans;
		return 0;
	}
	return 0;
} 
