#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[20][10005],f[10005],ans,cnt;
int mp[1005][1005];
struct node{
	int x,y,w;
}e[1000005];
bool vis[20];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].w);
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++) scanf("%lld",&c[i][j]);
	if(k==0){
		for(int i=1;i<=n;i++) f[i]=i;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int fx=find(e[i].x),fy=find(e[i].y);
			if(fx==fy) continue;
			else{
				f[fx]=fy;
				ans+=e[i].w;
				cnt++;
			}
			if(cnt==n-1) break;
		}
		printf("%lld",ans);
		return 0;
	}
	else{
		for(int i=1;i<=n;i++) f[i]=i;
		for(int d=1;d<=k;d++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						if(!vis[d]){
							if(mp[i][j]>c[d][i]+c[d][j]+c[d][0]){
							mp[i][j]=c[d][i]+c[d][j]+c[d][0];
							vis[d]=1;
							e[++m].x=i;
							e[m].y=j;
							e[m].w=mp[i][j];
						}
						
						}
						else{
							if(mp[i][j]>c[d][i]+c[d][j]){
							mp[i][j]=c[d][i]+c[d][j];
							e[++m].x=i;
							e[m].y=j;
							e[m].w=mp[i][j];
						}
						}
					}
				}
				
			} 
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int fx=find(e[i].x),fy=find(e[i].y);
			if(fx==fy) continue;
			else{
				f[fx]=fy;
				ans+=e[i].w;
				cnt++;
			}
			if(cnt==n-1) break;
		}
		printf("%lld",ans);
		return 0;
	}
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
