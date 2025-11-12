#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e3+10;
const LL mod=998244353;
int n,a[N],sum[N],l,r,includemin,includemax;
LL jiechen[N],ans;
void init(){
	jiechen[0]=1;
	for(int i=1;i<=5e3;++i) jiechen[i]=i*jiechen[i-1]%mod;
}
LL mfm(int x,int y){
	LL tmp=jiechen[y]/jiechen[y-x]/jiechen[x];
	return tmp;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
	for(int i=3;i<=n;++i){
		l=1,r=i-1;
		while(l<r){
			int mid=l+((r-l+1)>>1);
			if(sum[i-1]-sum[mid-1]>=a[i]) l=mid;
			else r=mid-1;
		}
		includemin=l;
		l=1,r=i-1;
		while(l<r){
			int mid=l+((r-l)>>1);
			if(sum[mid]>=a[i]) r=mid;
			else l=mid+1;
		}
		includemax=l;
		for(int j=max(2,includemax);j<=i-1;++j) ans=(ans+mfm(j,i-1))%mod;
		if(includemax>2) for(int j=i-includemin;j<=includemax-1;++j){
			l=1,r=i-j;
			while(l<r){
				int mid=l+((r-l+1)>>1);
				if(sum[mid+j-1]-sum[mid-1]>=a[i]) l=mid;
				else r=mid-1;
			}
			ans+=mfm(j,i-l)%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}
