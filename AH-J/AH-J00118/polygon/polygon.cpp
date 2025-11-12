#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5010],sum;
long long cn(long long t){
	long long s=t,m=t+1;
	for(long long i=1;i<t;i++){
		s*=(t-i);
		m+=s/(i+1);
	}
	return m;
}
long long f(long long u,long long b,long long c,long long t){
	if(b+c>u) return cn(t-1);
	long long x=c;
	for(long long i=t-1;i>=1;i--){
		x+=a[i];
		return f(u,b,x,i);
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=n;i>=3;i--){
		for(long long j=i-1;j>=2;j--){
			for(long long k=j-1;k>=1;k--){
				sum=(sum+f(a[i],a[j],a[k],k)%mod)%mod;
			}
		}
	}
	cout<<sum;
	return 0;
}
