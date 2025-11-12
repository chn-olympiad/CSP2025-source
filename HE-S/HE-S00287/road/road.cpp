#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m,k,ans,b1,cnt;
int fa[10004],size[10004];
struct O{
	int u,v,w;
}p[2000006];
int a[14][10005];
int f[14];
bool cmp(O a,O b){
	return a.w<b.w;
}
int getf(int x){
	if(fa[x]==x) return x;
	fa[x]=getf(fa[x]);
	return fa[x];
}
void sub(){
	for(int i=1;i<=n;i++){
		fa[i]=i;size[i]=1;
	}
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;i++){
		int a=getf(p[i].u);
		int b=getf(p[i].v);
		if(a==b) continue;
		ans+=p[i].w;
		b1++;
		if(b1==n-1) break;
		if(size[a]>=size[b]){
			fa[b]=a;
			size[a]+=size[b];
		}else{
			fa[a]=b;
			size[b]+=size[a];
		}
	}
	printf("%lld",ans);
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	cnt=m;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&p[i].u,&p[i].v,&p[i].w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(!a[i][j]) f[i]=j;
		}
	}
	if(!k){
		sub();return 0;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;size[i]=1;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(f[i]==j) continue;
			p[++cnt].u=f[i];
			p[cnt].v=j;
			p[cnt].w=a[i][j];
		}
	}
	sort(p+1,p+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int a=getf(p[i].u);
		int b=getf(p[i].v);
		if(a==b) continue;
		ans+=p[i].w;
		b1++;
		if(b1==n-1) break;
		if(size[a]>=size[b]){
			fa[b]=a;
			size[a]+=size[b];
		}else{
			fa[a]=b;
			size[b]+=size[a];
		}
	}
	printf("%lld",ans);
	return 0;
}
