#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,i,j,ans,k,t,a[N][5],vis[N],cnt[5];
struct ren{
	int v,w;
}d[N];
bool cmp(ren x,ren y){
	return x.v > y.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),k=0;
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) vis[i]=1;
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]) vis[i]=2;
			else vis[i]=3;
			cnt[vis[i]]++;
		}
		ans=0;
		for(i=1;i<=n;i++) ans+=a[i][vis[i]];
		if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2) printf("%d\n",ans);
		else{
			k=0;
			int flag=0;
			for(i=1;i<=3;i++) if(cnt[i]>n/2) flag=i;
			for(i=1;i<=n;i++){
				if(vis[i]!=flag) continue;				
				int mx=-1e9;
				for(j=1;j<=3;j++){
					if(vis[i]!=j) mx=max(mx,a[i][j]-a[i][vis[i]]);
				}
				d[++k]={mx,i};
			}
			sort(d+1,d+1+k,cmp);
			for(i=1;i<=cnt[flag]-n/2;i++) ans+=d[i].v;
			printf("%d\n",ans);
		}
	}
	return 0;
}
