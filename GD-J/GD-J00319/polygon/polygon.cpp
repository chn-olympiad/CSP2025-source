//polygon
#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[5007],f[5007][5007];
long long k(long long x,long long l){
	if(f[x][l]!=-1) return f[x][l];
	if(l<=0) return f[x][l]=(long long)pow(2,x)%mod;
	if(x==0) return f[x][l]=0;
	long long sum=0;
	for(int i=1; i<=x; i++){
		sum+=(k(i-1,l-a[i])%mod);
		sum%=mod;
	}
	return f[x][l]=sum%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,ans=0;
	memset(f,-1,sizeof(f));
	cin>>n;
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1,a+n+1); 
	for(int i=1; i<=n; i++){
		ans+=(k(i-1,a[i]+1)%mod);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
