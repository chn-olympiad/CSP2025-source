#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,fa[10055],sz[10055],p;
ll vis[15][10005],ans,sans;
int find(int x){
	return x==fa[x] ? x : fa[x]=find(fa[x]);
}
void merge(int x,int y){
	sz[find(x)]+=sz[find(y)];
	fa[find(y)]=find(x);
}
struct road{
	int l,r;
	ll c;
}a[1000005],g[10005];
bool cmp(road a,road b){
	return a.c<b.c;
}
void plant(int q){
	for(int i=1;i<=n;i++){
		fa[i]=i;sz[i]=1;
	}
	for(int i=n+1;i<=n+k;i++){
		fa[i]=i;sz[i]=0;
	}
	p=ans=0;
	for(int i=0;i<k;i++){
		if(((q>>i)&1)==1){
			//cout<<i+1<<' ';
			ans+=vis[i+1][0];
			for(int j=1;j<=n;j++){
				g[++p].l=n+i+1;
				g[p].r=j;
				g[p].c=vis[i+1][j];
			}
		}
	}
	//cout<<endl;
	sort(g+1,g+p+1,cmp);
	int x=1,y=1;
	while(x<=m&&(y<=p||!p)){
		int l=0,r=0;
		ll c=0;
		if(a[x].c<g[y].c||!p){
			l=a[x].l,r=a[x].r,c=a[x].c;
			x++;
		}
		else {
			l=g[y].l,r=g[y].r,c=g[y].c;
			y++;
		}
		if(find(l)==find(r))continue;
		//cout<<l<<' '<<r<<' '<<c<<endl;
		ans+=c;
		//cout<<l<<' '<<r<<' '<<sz[find(l)]<<' '<<sz[find(r)]<<endl;
		merge(l,r);
//		for(int i=1;i<=n;i++)cout<<sz[find(i)]<<' ';
//		cout<<endl;
		if(sz[find(l)]>=n){
			//cout<<find(l)<<' '<<sz[find(l)]<<endl;
			return ;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%lld",&a[i].l,&a[i].r,&a[i].c);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=k;i++){
		scanf("%lld",&vis[i][0]);
		for(int j=1;j<=n;j++)scanf("%lld",&vis[i][j]);
	}
	for(int i=0;i<(1<<k);i++){
		plant(i);//cout<<ans<<endl;
		if(!sans)sans=ans;
		else sans=min(sans,ans);
	}
	printf("%lld",sans);
	return 0;
} 
