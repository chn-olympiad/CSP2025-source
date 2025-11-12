#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,p[5005][5005],w[10005],cnt,ans=0,s=0;
int fa[10005];
struct st{
	int u,v,w;
}a[8000005];
bool cmp(st x,st y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		p[a[i].u][a[i].v]=a[i].w;
		p[a[i].v][a[i].u]=a[i].w;
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&w[j]);
			for(int k=1;k<j;k++){
				if(p[j][k]<=w[j]+w[k]+c&&p[j][k]!=0) continue;
				a[++cnt]={j,k,w[j]+w[k]+c};
				p[i][k]=w[j]+w[k]+c;
				p[k][i]=w[j]+w[k]+c;
			}
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		ans+=a[i].w;
		s++;
		if(s==n-1) break;
	}
	cout<<ans;
}
