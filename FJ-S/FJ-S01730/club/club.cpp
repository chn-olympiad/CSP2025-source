#include<bits/stdc++.h>
using namespace std;
int t,n,l,m[5],mystat;
long long ans;
struct st{
	int f[5],fi,se,th;
}a[100009],b[100009];
bool cmp1(st x,st y){
	if(x.f[x.fi]-x.f[x.se]==y.f[y.fi]-y.f[y.se]){
		return x.f[x.se]-x.f[x.th]>y.f[y.se]-y.f[y.th];
	}
	return x.f[x.fi]-x.f[x.se]>y.f[y.fi]-y.f[y.se];
}
bool cmp2(st x,st y){
	return x.f[x.se]-x.f[x.th]>y.f[y.se]-y.f[y.th];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		//memset(a,0,sizeof(a));
		//memset(b,0,sizeof(b));
		//So confusing. Deleting memset reduces 10 seconds and makes the huge sample pass.
		m[1]=0;m[2]=0;m[3]=0;
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].f[1],&a[i].f[2],&a[i].f[3]);
			mystat=0;
			if(a[i].f[1]>=a[i].f[2]){mystat+=4;}
			if(a[i].f[2]>=a[i].f[3]){mystat+=2;}
			if(a[i].f[1]>=a[i].f[3]){mystat++;}
			switch(mystat){
				case 7:{a[i].fi=1;a[i].se=2;a[i].th=3;break;}
				case 5:{a[i].fi=1;a[i].se=3;a[i].th=2;break;}
				case 3:{a[i].fi=2;a[i].se=1;a[i].th=3;break;}
				case 2:{a[i].fi=2;a[i].se=3;a[i].th=1;break;}
				case 4:{a[i].fi=3;a[i].se=1;a[i].th=2;break;}
				case 0:{a[i].fi=3;a[i].se=2;a[i].th=1;break;}
				default:{break;}
			}
		}
		sort(a+1,a+n+1,cmp1);
		l=0;
		for(int i=1;i<=n;i++){
			if(m[a[i].fi]<n/2){
				ans+=a[i].f[a[i].fi];
				m[a[i].fi]++;
			}else{
				/*l++;
				b[l].fi=a[i].fi; b[l].se=a[i].se; b[l].th=a[i].th;
				b[l].f[1]=a[i].f[1]; b[l].f[2]=a[i].f[2]; b[l].f[3]=a[i].f[3];*/
				b[++l]=a[i];
			}
		}
		sort(b+1,b+l+1,cmp2);
		for(int i=1;i<=l;i++){
			if(m[b[i].se]<n/2){
				ans+=b[i].f[b[i].se];
				m[b[i].se]++;
			}else{
				ans+=b[i].f[b[i].th];
				m[b[i].th]++;				
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
