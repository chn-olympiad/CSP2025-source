#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,ans,tot,tot2,tot3;
ll a[100100],b[100100],c[100100];
ll x[100100],y[100100],z[100100];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0,tot=0,tot2=0,tot3=0;
		scanf("%lld",&n);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			ans+=max(a[i],max(b[i],c[i]));
			if(a[i]>=b[i] && a[i]>=c[i]){
				x[++tot]=a[i]-max(b[i],c[i]);
			}
			else if(b[i]>=a[i] && b[i]>=c[i]){
				y[++tot2]=b[i]-max(c[i],a[i]);
			}
			else if(c[i]>=a[i] && c[i]>=b[i]){
				z[++tot3]=c[i]-max(b[i],a[i]);
			}
		}
		if(tot>(n/2)){
			sort(x+1,x+1+tot);
			tot=tot-(n/2);
			for(ll i=1;i<=tot;i++){
				ans-=x[i];
			}
		}
		else if(tot2>(n/2)){
			sort(y+1,y+1+tot2);
			tot2=tot2-(n/2);
			for(ll i=1;i<=tot2;i++){
				ans-=y[i];
			}
		}
		else if(tot3>(n/2)){
			sort(z+1,z+1+tot3);
			tot3=tot3-(n/2);
			for(ll i=1;i<=tot3;i++){
				ans-=z[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
