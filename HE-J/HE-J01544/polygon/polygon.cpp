#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,b[5005];
const long long mod=998244353;
long long fpow(int a,int b){
	long long res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	b[0]=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)b[i]=b[i-1]*i%mod;
	long long ans=0;
	for(long long i=3;i<=n;i++){
		long long aa=b[n],bb=b[n-i],cc=b[i];
		ans+=aa/bb/cc%mod;
	}
	cout<<ans;
	return 0;
}
