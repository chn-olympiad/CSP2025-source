#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
long long a[2*10005],b[2*10005],c[2*10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;++i)
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		sort(a+1,a+n+1);
		for(int i=n;i>n/2;--i)
			ans+=a[i];
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}
