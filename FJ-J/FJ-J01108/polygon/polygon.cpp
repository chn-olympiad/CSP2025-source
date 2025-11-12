#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005];
long long ans;
long long jc(int p){
	long long sum=1;
	for(int i=1;i<=p;i++){
		sum*=i;
	}
	return sum;
}
long long C(int x,int y){
	return jc(y)/(jc(x)*jc(y-x))%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool f=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			f=0;
		}
	}
	if(f){
		for(int len=3;len<=n;len++){
			ans+=C(len,n);
			ans%=mod;
		}
	}
	printf("%lld",ans);
	return 0;
}
