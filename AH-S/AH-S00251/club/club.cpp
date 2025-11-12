#include<bits/stdc++.h>
using namespace std;
struct awa{
	int k,ix;
}p[100005][3],dim[100005];
int T,n;
int cnt[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int ans=0,cntt=0; memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i][0].k,&p[i][1].k,&p[i][2].k);
			p[i][0].ix=0,p[i][1].ix=1,p[i][2].ix=2;
			sort(p[i],p[i]+3,[](awa a,awa b){
				return a.k>b.k;
			});
			dim[i]={p[i][0].k-p[i][1].k,i};
		}
		sort(dim+1,dim+n+1,[](awa a,awa b){
			return a.k>b.k;		
		});
		for(int i=1;i<=n;i++){
			if(cnt[p[dim[i].ix][0].ix]<(n>>1))ans+=p[dim[i].ix][0].k,cnt[p[dim[i].ix][0].ix]++;
			else dim[++cntt]={p[dim[i].ix][1].k-p[dim[i].ix][2].k,dim[i].ix};
		}
		sort(dim+1,dim+cntt+1,[](awa a,awa b){
			return a.k>b.k;
		});
		for(int i=1;i<=cntt;i++){
			if(cnt[p[dim[i].ix][1].ix]<(n>>1))ans+=p[dim[i].ix][1].k,cnt[p[dim[i].ix][1].ix]++;
			else ans+=p[dim[i].ix][2].k,cnt[p[dim[i].ix][2].ix]++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
