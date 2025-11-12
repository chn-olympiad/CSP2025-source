#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long check(long long x){
	long long cnt=1,num=2;
	while(cnt*2<=x){
		num*=num;
		num%=998244353;
		cnt*=2;
	}
	for(int k=1;k<=x-cnt;k++){
		num*=2;
		num%=998244353;
	}
	return num%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)cout<<1;
		else cout<<0;
		return 0;
	}
	long long ans=check(n-2)-1;
	printf("%lld",ans);
	return 0;
}
