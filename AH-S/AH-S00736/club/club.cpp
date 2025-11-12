#include<bits/stdc++.h>
using namespace std;
struct man{
	long long a,b,c,dis;
}k[100001];
bool cmp(man aa,man bb){
	return aa.dis<bb.dis;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,i;
	scanf("%lld",&t);
	while(t--){
		long long opa=0,opb=0,opc=0,ans=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld%lld%lld",&k[i].a,&k[i].b,&k[i].c);
			k[i].dis=1145141919;
		}
		for(i=1;i<=n;i++){
			if(k[i].a==max(k[i].a,max(k[i].b,k[i].c))) opa++;
			else if(k[i].b==max(k[i].a,max(k[i].b,k[i].c))) opb++;
			else opc++;
		}
		for(i=1;i<=n;i++){
			ans+=max(k[i].a,max(k[i].b,k[i].c));
		}
		if(opa<=n/2&&opb<=n/2&&opc<=n/2){
			printf("%lld\n",ans);
		}
		else {
			if(opa>n/2){
				for(i=1;i<=n;i++){
					if(k[i].a==max(k[i].a,max(k[i].b,k[i].c))) {
						if(k[i].b>=k[i].c) k[i].dis=k[i].a-k[i].b;
						else k[i].dis=k[i].a-k[i].c;
					}
				}
				sort(k+1,k+n+1,cmp);
				for(i=1;i<=opa-n/2;i++){
					ans-=k[i].dis;
				}
			}
			if(opb>n/2){
				for(i=1;i<=n;i++){
					if(k[i].b==max(k[i].a,max(k[i].b,k[i].c))) {
						if(k[i].a>=k[i].c) k[i].dis=k[i].b-k[i].a;
						else k[i].dis=k[i].b-k[i].c;
					}
				}
				sort(k+1,k+n+1,cmp);
				for(i=1;i<=opb-n/2;i++){
					ans-=k[i].dis;
				}
			}
			if(opc>n/2){
				for(i=1;i<=n;i++){
					if(k[i].c==max(k[i].a,max(k[i].b,k[i].c))) {
						if(k[i].a>=k[i].b) k[i].dis=k[i].c-k[i].a;
						else k[i].dis=k[i].c-k[i].b;
					}
				}
				sort(k+1,k+n+1,cmp);
				for(i=1;i<=opc-n/2;i++){
					ans-=k[i].dis;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
