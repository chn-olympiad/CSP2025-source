#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],i,j,ma,ans,h,b[1050000],d[1050000],c[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		h=max(h,a[i]);
	}
	for(i=1;i<=n;i++){
		ma=0;
		for(j=i;j>=1;j--){
			ma^=a[j];
			c[i]=max(c[i],c[j]);
			if(ma==k)c[i]=max(c[i],c[j-1]+1);
			if(ma==0)break;
		}
		ans=max(ans,c[i]);
	}
	cout<<ans;
	return 0;
}
