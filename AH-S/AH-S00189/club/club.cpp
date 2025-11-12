#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll t,n,b[5];
ll xx[N],yy[N],zz[N];
ll xxx,yyy,zzz;
struct node{
	ll aa,bb,cc,nmax,maxx,dlt;
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		xxx=0;
		yyy=0;
		zzz=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].aa,&a[i].bb,&a[i].cc);
			b[1]=a[i].aa;
			b[2]=a[i].bb;
			b[3]=a[i].cc;
			sort(b+1,b+1+3);
			a[i].nmax=b[3];
			a[i].maxx=b[2];
			a[i].dlt=a[i].nmax-a[i].maxx;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].aa==a[i].nmax){
				xx[++xxx]=a[i].dlt;
			}else if(a[i].bb==a[i].nmax){
				yy[++yyy]=a[i].dlt;
			}else if(a[i].cc==a[i].nmax){
				zz[++zzz]=a[i].dlt;
			}
			ans+=a[i].nmax;
		}
		if(xxx>n/2){
			int ab=xxx-n/2;
			sort(xx,xx+xxx+1);
			for(int i=1;i<=ab;i++){
				ans-=xx[i];
			}
		}
		if(yyy>n/2){
			int ab=yyy-n/2;
			sort(yy,yy+yyy+1);
			for(int i=1;i<=ab;i++){
				ans-=yy[i];
			}
		}
		if(zzz>n/2){
			int ab=zzz-n/2;
			sort(zz,zz+zzz+1);
			for(int i=1;i<=ab;i++){
				ans-=zz[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
