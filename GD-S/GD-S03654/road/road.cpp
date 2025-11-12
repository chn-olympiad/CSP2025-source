#include<bits/stdc++.h>
using namespace std;
struct line{
	int x,y,w;
}l[2000001];
int f[20001],li,c[20001],vis[20001],p[20001];
bool cmp(line x,line y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&l[i].x,&l[i].y,&l[i].w);
	}
	li=m;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			int w;
			scanf("%d",&w);
			l[++li].x=n+i;
			l[li].y=j;
			l[li].w=w;
		}
	}
	sort(l+1,l+1+li,cmp);
	long long ans=1e18;
	for(int i=0;i<(1<<k);i++){
		long long s=0;
		int si=0,sc=0;
		for(int j=1;j<=k;j++){
			if((i>>j-1)&1){
				s+=c[j];
				p[j]=i+1;
			}
		}
		for(int j=1;j<=n+k;j++) f[j]=j,vis[j]=0;
		for(int j=1;j<=li;j++){
			if(l[j].x>n&&p[l[j].x-n]!=i+1) continue;
			if(find(l[j].x)!=find(l[j].y)){
				f[find(l[j].x)]=find(l[j].y);
				s+=l[j].w;
				if(l[j].x>n&&!vis[l[j].x]) vis[l[j].x]=1,sc++;
				si++;
			}
			if(si==n+sc-1) break;
		}
		ans=min(ans,s);
	}
	printf("%lld",ans);
	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
