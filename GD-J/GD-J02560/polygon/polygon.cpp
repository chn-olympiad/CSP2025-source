#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo i,j,k,l,n,m,mm,r,s,ss,a[1000001],b[500001],mod=998244353,c[500001],d[500001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		r+=a[i];
	}
	d[0]=1;
	for(i=1;i<=n;i++){
		d[i]=d[i-1]*2%mod;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		ss+=a[i-1];
		if(i!=1){
			if(a[i]<ss*2+1)s=1;
		}
	}
	if(!s){
		printf("0");
		return 0;
	}
	ss=0,s=0;
	b[a[1]+a[2]]=1;
	c[a[1]+a[2]]=1;
	for(i=3;i<=n;i++){
		s=((d[i-1]-i+mod)%mod-b[a[i]]+mod)%mod;
		//cout<<s<<"\n";
		ss+=s;
		ss%=mod;
		for(j=r;j>=a[i]+2;j--){
			c[j]+=c[j-a[i]];
			c[j]%=mod;
		}
		for(j=1;j<i;j++){
			c[a[i]+a[j]]++;
			c[a[i]+a[j]]%=mod;
		}
		for(j=2;j<=r;j++){
			b[j]=(b[j-1]+c[j])%mod;
		}
	}
	printf("%lld",ss);
	return 0;
}

