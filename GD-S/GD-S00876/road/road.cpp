#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node{
	int op,u,v,w;
}a[1000006];
bool cmp(Node a,Node b){return a.w<b.w;}
int fa[10020];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int c[15];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,w,fx,fy,i,j,s;
	ll ans=1e18,sum;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w),a[i].op=0;
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=n;i++) fa[i]=i;
	int t=0;
	for(i=1;i<=m;i++){
		fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy){
			a[++t]=a[i];
			fa[fx]=fy;
		}
	}
	m=t;
	for(i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(j=1;j<=n;j++){
			scanf("%d",&w);
			a[++m].u=j;a[m].v=n+i;a[m].w=w;a[m].op=i;
		}
	}
	sort(a+1,a+m+1,cmp);
	for(j=0;j<(1<<k);j++){
		sum=s=0;
		for(i=1;i<=n+k;i++) fa[i]=i;
		for(i=1;i<=m;i++){
			if(a[i].op&&!(j&(1<<(a[i].op-1)))) continue;
			fx=find(a[i].u),fy=find(a[i].v);
			if(fx==fy) continue;
			s++;
			fa[fx]=fy;
			sum+=a[i].w;
		}
		for(i=1;i<=k;i++){
			if(j&(1<<(i-1))) sum+=c[i],s--;
		}
		if(s==n-1) ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
} 
