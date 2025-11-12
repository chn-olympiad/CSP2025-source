#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N],b[N],c[N],ans,g[N],h[N],r[N],res;
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cin>>n;
		ans=0;
		res=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			ans+=a[i];
		}
		for(int i=1;i<=n;i++){
			g[i]=b[i]-a[i];
			h[i]=c[i]-a[i];
		}
		for(int i=1;i<=n;i++){
			r[i]=max(g[i],h[i]);
		}
		sort(r+1,r+n+1);
		for(int i=n;i>n/2;i--){
			ans+=r[i];
		}
		res=max(res,ans);
		ans=0;
		for(int i=1;i<=n;i++){
			ans+=b[i];
		}
		for(int i=1;i<=n;i++){
			g[i]=a[i]-b[i];
			h[i]=c[i]-b[i];
		}
		for(int i=1;i<=n;i++){
			r[i]=max(g[i],h[i]);
		}
		sort(r+1,r+n+1);
		for(int i=n;i>n/2;i--){
			ans+=r[i];
		}
		res=max(res,ans);
		ans=0;
		for(int i=1;i<=n;i++){
			ans+=c[i];
		}
		for(int i=1;i<=n;i++){
			g[i]=b[i]-c[i];
			h[i]=a[i]-c[i];
		}
		for(int i=1;i<=n;i++){
			r[i]=max(g[i],h[i]);
		}
		sort(r+1,r+n+1);
		for(int i=n;i>n/2;i--){
			ans+=r[i];
		}
		res=max(res,ans);
		printf("%lld\n",res);
	}
	return 0;
}
