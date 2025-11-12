#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],d[1000],ddd,ans;
long long ksm(long long x,long long y){
	long long aaa=y,bbb=1;
	while(x){
		if(x%2==1){
			bbb=(bbb*aaa)%998244353;
		}
		x/=2;
		aaa=(aaa*aaa)%998244353;
	}
	return bbb;
}
void dp(long long x,long long s,long long y,long long w){
	if(x>n){
		if(s>y*2&&w>=3) ans++;
		return ;
	}
	dp(x+1,s,y,w);
	dp(x+1,s+a[x],max(y,a[x]),w+1);
	return ;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		ddd=max(ddd,a[i]);
	}
	if(n<=20){
		dp(1,0,0,0);
		printf("%lld",ans);
		return 0;
	}
	if(ddd==1){
		ans=(((ksm(n,2)-1-n+998244353)%998244353)-(((n*(n-1))/2)%998244353)+998244353)%998244353;
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
