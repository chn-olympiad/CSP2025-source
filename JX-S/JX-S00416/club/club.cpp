#include<bits/stdc++.h>
using namespace std;
struct ren{
	int a;
	int b;
	int c;
};
long long t,n,cnt1=0,cnt2=0,cnt3=0,ans=0,f=0;
ren g[110000];
int mmax(ren x){
	return max(x.a,max(x.b,x.c));
}
bool cmp(ren x,ren y){
	return mmax(x)>mmax(y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		f=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			int a1,b1,c1;
			scanf("%d%d%d",&g[i].a,&g[i].b,&g[i].c);
		}
		sort(g+1,g+1+n,cmp);
		for(int i=1;i<=n;i++){
			int x=mmax(g[i]);
			if(x==g[i].a){
				cnt1++;
			}else if(x==g[i].b){
				cnt2++;
			}else{
				cnt3++;
			}
			ans+=x;
			if(cnt1>=n/2&&f==0){
				for(int j=1;j<=n;j++){
					g[j].a=0;
				}
				f=1;
				sort(g+1+i,g+1+n,cmp);
			}
			if(cnt2>=n/2&&f==0){
				for(int j=1;j<=n;j++){
					g[j].b=0;
				}
				f=1;
				sort(g+1+i,g+1+n,cmp);
			}
			if(cnt3>=n/2&&f==0){
				for(int j=1;j<=n;j++){
					g[j].c=0;
				}
				f=1;
				sort(g+1+i,g+1+n,cmp);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
