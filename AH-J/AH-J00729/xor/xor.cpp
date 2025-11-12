#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,sumxor[500010],a[500010],cnt0,cnt1;
bool fa=true,fb=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sumxor[i]=sumxor[i-1]^a[i];
		cnt0+=a[i]==0;
		cnt1+=a[i]==1;
		if(a[i]!=0) fa=false;
		if(a[i]>1) fb=false;
	}
	if(k==0&&fa){
		printf("%lld",n/2);
		return 0;
	}else if(fb&&k<=1){
		if(k==0) printf("%lld",cnt0+cnt1/2);
		else printf("%lld",cnt1);
	}
	return 0;
}
