#include <bits/stdc++.h>
using namespace std;
long long n,a[5050],ans=0;
void g(long long x,long long y,long long z,long long sum){
	if(sum>=3&&sum<=n&&2*y<z)ans++;
	if(sum<=n){
		for(long long i=x+1;i<=n;i++){
			g(i,max(y,a[i]),z+a[i],sum+1);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			g(j,max(a[i],a[j]),a[i]+a[j],2);
		}
	}
	cout<<ans%998244353;
	return 0;
}
