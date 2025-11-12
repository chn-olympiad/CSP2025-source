#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans,mod=998244353,flag;
void dg(long long x,long long sum,long long p,long long maxx){
	if(x==0){
		if(sum>maxx*2)ans=(ans+1)%mod;
		return;
	}
	for(long long i=p;i<=n;i++){
		long long maxxx=maxx;
		maxx=max(maxx,a[i]);
		dg(x-1,sum+a[i],i+1,maxx);
		maxx=maxxx;
	}
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(long long i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)flag=1;
	}
	if(flag==0){
		long long sum=0;
		for(long long i=3;i<=n;i++){
			ans=1;
			for(long long j=0;j<i;j++)ans*=(n-j);
			for(long long j=0;j<i;j++)ans/=(j+1);
			sum=(ans+sum)%mod;
		}
		printf("%d",sum%mod);
		return 0;
	}
	for(long long i=3;i<=n;i++)dg(i,0,1,0);
	printf("%d",ans%mod);
}
