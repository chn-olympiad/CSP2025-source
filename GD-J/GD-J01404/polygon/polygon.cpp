#include<bits/stdc++.h>
using namespace std;
int n,sum,maxx=-100000,a[5005];long long jc[5005],f[5005];const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		maxx=max(maxx,a[i]);
	}
	for(int i=0;i<=n;i++){
		if(i==1 || i==0) jc[i]=1;
		else{
			jc[i]=(i*jc[i-1])%(long long)mod;
			if(jc[i]==0) jc[i]=1;
		}
	}
	if(n==3){
		if(sum>2*maxx) printf("1");
		else printf("0");
		return 0;
	}
	if(maxx==1){
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=(jc[n]/(((jc[i]*jc[n-i])%(long long)mod)==0?1:((jc[i]*jc[n-i])%(long long)mod)));
			ans%=(long long)mod;
		}
		printf("%lld",ans%(long long)mod);
		return 0;
	}
	return 0;
}
