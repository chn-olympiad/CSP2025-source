#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,tree[10020],fa[10005],vis[20];
struct point{
	int u,v,w;
}a[5000005];
queue<pair<int,int> > q;
bool cmp(point x,point y){
	return x.w<y.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int check(){
	for(int i=1;i<n;i++){
		int fx=find(i),fy=find(i+1);
		if(fx!=fy) return false;
	}
	return true;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=1;i<=m;i++){
			int fu=find(a[i].u),fv=find(a[i].v);
			if(fu!=fv){
				fa[fu]=fv;
				ans+=a[i].w;
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=m;i++) {
			cin>>a[i].u>>a[i].v>>a[i].w;
		}
		for(int i=1;i<=n+k;i++) fa[i]=i;
		int cnt=m;
		for(int i=1;i<=k;i++){
			for(int j=0;j<=n;j++){
				if(j==0) cin>>tree[n+i];
				else{
					int c;
					cin>>c;
					a[++cnt]={n+i,j,c+tree[n+i]};
				}
			}
		}
		sort(a+1,a+cnt+1,cmp);
		int ans=0;
		for(int i=1;i<=cnt;i++){
			int fu=find(a[i].u),fv=find(a[i].v);
			if(fu!=fv&&check()==false){
				fa[fu]=fv;
				ans+=a[i].w;
				if(a[i].u>n) ans-=tree[a[i].u];
				if(a[i].u>n&&vis[a[i].u-n]==false) ans+=tree[a[i].u],vis[a[i].u-n]=true;
			}
		}
		cout<<ans;
	}
}


