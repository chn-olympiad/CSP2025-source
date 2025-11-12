#include<bits/stdc++.h>
using namespace std;
long long a[5010];
const long long mod=998244353;
long long qpow(long long x,long long y){
	long long ans=1;
	while(y){
		if(y&1){
			ans*=x;
			ans%=mod;
		}
		x=x*x;
		x%=mod;
		y>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,mx=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}if(mx==1){
		long long ans=0;
		for(long long i=3;i<=n;i++){
			long long m=i;
			m=min(m,n-m);
			long long a1=1,b1=1;
			for(long long j=0;j<m;j++){
				a1*=(n-j);
				a1%=mod;
			}
			for(long long j=1;j<=m;j++){
				b1*=j;
				b1%=mod;
			}
			long long inv=qpow(b1,mod-2);
			ans+=a1*inv%mod;
			ans%=mod;
		}
		cout<<ans;
	}
	else {
		long long temp=(1<<n),ans=0;
		for(long long i=0;i<temp;i++){
			long long sum=0,maxv=0;
			long long t=i,cnt=0;
			bool flag=0;
			while(t){
				cnt++;
				if(t&1){
					sum+=a[cnt];
					maxv=max(maxv,a[cnt]);
					if(sum>mx*2){
						flag=1;
						ans++;
						if(ans>=mod)ans%=mod;
					}
				}
				if(flag==1) break;
				t>>=1;
			}
			if(flag==1) continue;
			if(sum>maxv*2){
				ans++;
				if(ans>=mod)ans%=mod;
			}
		}
		cout<<ans%mod;
		exit(0);
	}
	return 0;
}