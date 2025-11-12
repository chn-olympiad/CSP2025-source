#include <cstdio>
#include <algorithm>
using namespace std;

int t,n,b[100005];
struct node{
	int fi,nfi;
	int se,nse;
	int th,nth;
	int de;
}a[100005];
void work(int i){
	if(a[i].nfi<a[i].nse) {swap(a[i].nfi,a[i].nse);swap(a[i].fi,a[i].se);}
	if(a[i].nfi<a[i].nth) {swap(a[i].nfi,a[i].nth);swap(a[i].fi,a[i].th);}
	if(a[i].nse<a[i].nth) {swap(a[i].nse,a[i].nth);swap(a[i].se,a[i].th);}
	return;
}
int work2(int m1,int m2,int m3){
	if(m1>m2&&m1>m3) return 1;
	if(m2>m1&&m2>m3) return 2;
	return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int m1=0,m2=0,m3=0,ans=0,k=n/2;
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&a[i].nfi,&a[i].nse,&a[i].nth);
			a[i].fi=1;
			a[i].se=2;
			a[i].th=3;
			work(i);
			a[i].de=a[i].nfi-a[i].nse;
			if(a[i].fi==1) m1++;
			if(a[i].fi==2) m2++;
			if(a[i].fi==3) m3++;
			ans+=a[i].nfi;
		}
		if(m1<=k&&m2<=k&&m3<=k) printf("%d\n",ans);
		else{
			int cnt=max(max(m1,m2),m3)-k,pro=work2(m1,m2,m3),tmp=0;
			for(int i=1;i<=n;i++) if(a[i].fi==pro) b[++tmp]=a[i].de;
			sort(b+1,b+tmp+1);
			for(int i=1;i<=cnt;i++) ans-=b[i];
			printf("%d\n",ans);
		}
	}
	return 0;
}
