#include<bits/stdc++.h>
#define int long long
//#define ll long long
using namespace std;
const int N=1e5+10,M=3e5+10;
int t,n,cnt[4],mid[4],ans;
bool vis[N];
struct px{
	int id,a,d,v;
}x[M];
bool cmp(px x,px y){
	return x.v>y.v;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		memset(vis,0,sizeof vis);
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&x[i].a,&x[n+i].a,&x[(n<<1)+i].a);
			mid[1]=x[i].a,mid[2]=x[n+i].a,mid[3]=x[(n<<1)+i].a;
			sort(mid+1,mid+4);
			x[i].id=x[n+i].id=x[(n<<1)+i].id=i;
			x[i].d=1,x[n+i].d=2,x[(n<<1)+i].d=3;
			x[i].v=x[i].a-mid[2];
			x[n+i].v=x[n+i].a-mid[2];
			x[(n<<1)+i].v=x[(n<<1)+i].a-mid[2];
		}
		sort(x+1,x+n*3+1,cmp);
		for(int i=1;i<=n*3;i++){
			if(!vis[x[i].id]){
				if(cnt[x[i].d]<(n>>1)){
					cnt[x[i].d]++;
					ans+=x[i].a;
					vis[x[i].id]=1;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
