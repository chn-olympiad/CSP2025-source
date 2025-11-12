#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[15],b[15][10005],ans=LLONG_MAX;
struct node{
	int a,b,c;
}a[3000005];
int vis[20005],fa[20005],bz[20005];
bool cmp(node xx,node yy){
	return xx.c<yy.c;
}
inline int read(){
	int ans=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void kruskal(int X){
	X+=n;
	int res=0;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		if((!vis[a[i].a]&&a[i].a>n)||(!vis[a[i].b]&&a[i].b>n)) continue;
		int f1=find(a[i].a);
		int f2=find(a[i].b);
		if(f1!=f2){
			fa[f1]=f2;
			res+=a[i].c;
			X--;
			if(bz[a[i].b]){
				res+=bz[a[i].b];
				bz[a[i].b]=0;
			}
			if(bz[a[i].a]){
				res+=bz[a[i].a];
				bz[a[i].a]=0;
			}
			if(res>=ans) return ;
			if(X==0) break;
		}
	}
	ans=min(ans,res);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		a[i].a=read(),a[i].b=read(),a[i].c=read();
	}
	if(k==0){
		kruskal(0);
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			b[i][j]=read();
			a[++m]={i+n,j,b[i][j]};
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int b=0;b<(1<<k);b++){
		memset(vis,0,sizeof(vis));
		int sum=0;
		for(int i=0;i<k;i++){
			if((b>>i)&1){
				int t=i+1+n;
				vis[t]=1;
				bz[t]=c[i+1];
				sum++;
			}
		}
		kruskal(sum);
	}
	printf("%lld\n",ans);
	return 0;
}
