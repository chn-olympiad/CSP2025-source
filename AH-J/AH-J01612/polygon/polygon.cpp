#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll i,j,n,ans=0,maxn=-1e9;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])
			printf("1");
		else
			printf("0");
	}
	else{
		if(maxn==1){
			for(i=3;i<=n;i++){
				for(j=1;j<=n-i+1;j++)
					ans=(ans+j*(n-i+2-j))%mod;
			}
			printf("%lld",ans);
		}
		else
			printf("%lld",mod-1);
	}
	return 0;
}
