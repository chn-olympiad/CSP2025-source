#include<bits/stdc++.h>
using namespace std;
long long n,t,a[4],p[4],ans;
struct w{
	long long zd,cd,zs,cs;
}b[100009];
bool cmp(w x,w y){
	return x.zd+y.cd>y.zd+x.cd;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		p[1]=p[2]=p[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
			long long p1=a[0],p2=a[1],p3=a[2];
			sort(a,a+3);
			b[i].zd=a[2];b[i].cd=a[1];
			if(b[i].zd==p1) b[i].zs=1;
			if(b[i].zd==p2) b[i].zs=2;
			if(b[i].zd==p3) b[i].zs=3;
			if(b[i].cd==p1) b[i].cs=1;
			if(b[i].cd==p2) b[i].cs=2;
			if(b[i].cd==p3) b[i].cs=3;
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(p[b[i].zs]<n/2){
				ans+=b[i].zd;
				p[b[i].zs]++;
			}
			else{
				ans+=b[i].cd;
				p[b[i].cs]++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
