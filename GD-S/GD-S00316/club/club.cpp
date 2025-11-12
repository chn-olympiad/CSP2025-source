#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5;
int T,n;
int cnta,cntb,cntc,tot;
ll ans;
int a[N+5],b[N+5],c[N+5];
int va[N+5],vb[N+5],vc[N+5];
ll tmp[N+5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		cnta=cntb=cntc=0;
		for(int i=1;i<=n;++i){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ans+=a[i];
				va[++cnta]=i; 
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				ans+=b[i];
				vb[++cntb]=i; 
			}
			else{
				ans+=c[i];
				vc[++cntc]=i; 
			}
		}
		tot=0;
		if(cnta>n/2){
			for(int i=1;i<=cnta;++i)
				tmp[++tot]=a[va[i]]-max(b[va[i]],c[va[i]]);
		}
		else if(cntb>n/2){
			for(int i=1;i<=cntb;++i)
				tmp[++tot]=b[vb[i]]-max(a[vb[i]],c[vb[i]]);
		}
		else if(cntc>n/2){
			for(int i=1;i<=cntc;++i)
				tmp[++tot]=c[vc[i]]-max(a[vc[i]],b[vc[i]]);
		}
		if(tot){
			sort(tmp+1,tmp+1+tot);
			for(int i=1;i<=max(cnta,max(cntb,cntc))-n/2;++i)
				ans-=tmp[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
