#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,u,v,w,ans,a[100005][3];
struct node{int u,v,w;}b[100005];
int cmp(node x,node y){return x.u<y.u;}
int cpm(node x,node y){return x.v<y.v;}
int mpc(node x,node y){return x.w<y.w;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n),ans=u=v=w=0;
		for(int i=1,x,y,z;i<=n;i++){
			scanf("%lld%lld%lld",&x,&y,&z);
			if(x>=y&&x>=z) b[++u].u=x-max(y,z);
			else if(y>=z) b[++v].v=y-max(x,z);
			else b[++w].w=z-max(x,y);
			ans+=max({x,y,z});
		}
		if(u<=n/2&&v<=n/2&&w<=n/2) printf("%lld\n",ans);
		else if(u>n/2){
			sort(b+1,b+1+u,cmp);
			for(int i=1;u>n/2;i++) ans-=b[i].u,u--;
			printf("%lld\n",ans);
		}
		else if(v>n/2){
			sort(b+1,b+1+v,cpm);
			for(int i=1;v>n/2;i++) ans-=b[i].v,v--;
			printf("%lld\n",ans);
		}
		else{
			sort(b+1,b+1+w,mpc);
			for(int i=1;w>n/2;i++) ans-=b[i].w,w--;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
