#include<bits/stdc++.h>
using namespace std;
const long long N=5010;
const long long mod=998244353;
long long n,ans;
long long q[N],jc[N],ny[N];
long long maxn;
long long ksm(long long n,long long m,long long mo){
	n%=mo;
	long long res=1;
	while(m){
		if(m&1){
			res*=n;
			res%=mo;
		}
		n*=n;
		n%=mo;
		m/=2;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>q[i];
		maxn=max(maxn,q[i]);
	}
	if(maxn==1){
		jc[0]=1;
		for(int i=1;i<=n;i++){
			jc[i]=jc[i-1]*i;
			jc[i]%=mod;
		}
		ny[n]=jc[n];
	//	cout<<ksm(2,3,mod);
		ny[n]=ksm(ny[n],mod-2,mod);
	//	cout<<111;
		for(int i=n;i>1;i--){
			ny[i-1]=ny[i]*i;
			ny[i-1]%=mod;
		}
		ny[0]=1;
		//cout<<111;
		for(int i=3;i<=n;i++){
			ans+=((jc[n]*ny[n-i])%mod*ny[i])%mod;
		//	cout<<i<<" "<<jc[n]<<" "<<ny[n-i]<<" "<<ny[i]<<" "<<(jc[n]*ny[n-i]*ny[i])%mod<<"\n";
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	for(long long i=0;i<(1<<n);i++){
		long long maxx=0,sum=0,cnt=0;
		for(long long j=0;j<n;j++){
			if((i>>j)&1){
				maxx=max(maxx,q[j+1]);
				sum+=q[j+1];
				cnt++;
			}
		}
		if(sum>maxx*2&&cnt>=3){
			ans++;
			ans%=mod;
		}
	}
	cout<<ans%mod;
	return 0;
} 