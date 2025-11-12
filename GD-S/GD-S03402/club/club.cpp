#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long a,b,c,x;
}a[100005];
bool cmp(edge b,edge c){
	if(b.x==c.x)return max(b.a,max(b.b,b.c))>max(c.a,max(c.b,c.c));
	return b.x>c.x;
}
long long t,n,i,aa,bb,cc,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n),ans=aa=bb=cc=0;
		for(i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			a[i].x=max(a[i].a,max(a[i].b,a[i].c))-min(a[i].a,max(a[i].b,a[i].c));
		}
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n;i++){
			if(max(a[i].a,max(a[i].b,a[i].c))==a[i].a){
				if(aa==n/2){
					if(a[i].b>a[i].c&&bb<n/2){
						ans+=a[i].b,bb++;
					}else ans+=a[i].c,cc++;
				}else{
					ans+=a[i].a,aa++;
				}
			}else if(max(a[i].a,max(a[i].b,a[i].c))==a[i].b){
				if(bb==n/2){
					if(a[i].a>a[i].c&&aa<n/2){
						ans+=a[i].a,aa++;
					}else ans+=a[i].c,cc++;
				}else{
					ans+=a[i].b,bb++;
				}
			}else{
				if(cc==n/2){
					if(a[i].a>a[i].b&&aa<n/2){
						ans+=a[i].a,aa++;
					}else ans+=a[i].b,bb++;
				}else{
					ans+=a[i].c,cc++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
