#include<bits/stdc++.h>
using namespace std;
long long a[5005];
const long long mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}
	else if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		long long ans=0;
		for(long long i=3;i<=n;i++){
			long long shang=1;
			long long xia=1;
			for(long long j=1;j<=i;j++){
				shang=shang*j;
				xia=xia*(n-j+1);
			}
			ans+=xia/shang;
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}