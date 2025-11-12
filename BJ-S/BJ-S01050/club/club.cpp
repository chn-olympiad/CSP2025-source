#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+5;
struct stu{
	ll a,b,c;
}a[N];
ll n,ac,bc,cc,ans;
bool _acmp(stu x,stu y){
	return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);
}
bool _bcmp(stu x,stu y){
	return x.b-max(x.a,x.c)>y.b-max(y.a,y.c);
}
bool _ccmp(stu x,stu y){
	return x.c-max(x.b,x.a)>y.c-max(y.b,y.a);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		ans=ac=bc=cc=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>a[i].b&&a[i].a>a[i].c) ac++;
			else if(a[i].a<a[i].b&&a[i].b>a[i].c) bc++;
			else if(a[i].a<a[i].c&&a[i].b<a[i].c) cc++;
		}
		if(ac>n/2){
			sort(a+1,a+1+n,_acmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].a;
			for(int i=n/2+1;i<=n;i++) ans+=max(a[i].b,a[i].c);
		}else if(bc>n/2){
			sort(a+1,a+1+n,_bcmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].b;
			for(int i=n/2+1;i<=n;i++) ans+=max(a[i].a,a[i].c);
		}else if(cc>n/2){
			sort(a+1,a+1+n,_ccmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].c;
			for(int i=n/2+1;i<=n;i++) ans+=max(a[i].b,a[i].a);
		}
		else{
			for(int i=1;i<=n;i++) ans+=max(a[i].a,max(a[i].b,a[i].c));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
