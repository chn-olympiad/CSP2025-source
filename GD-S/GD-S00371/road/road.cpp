#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[20005],sz[200005],c[10005];
map<int,map<int,long long> > mp;
long long ans;
struct o{
	long long u,v,w;
}a[2000005];
bool cmd(o x,o y){
	return x.w<y.w;
}int fun(int x){
	if(fa[x]==x) return x;
	return fa[x]=fun(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			mp[i][j]=1e15;
		}
	}
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		if(u>v) swap(u,v);
		mp[u][v]=min(mp[u][v],w);
	}for(int i=1;i<=k;i++){
		long long c1;
		cin>>c1;
		for(int j=1;j<=n;j++){
			cin>>c[j];
		}bool p=0;
		int uu=0,vv=0;
		for(int j=1;j<n;j++){
			for(int jj=j+1;jj<=n;jj++){
				if(c[j]+c[jj]+c1<mp[j][jj]){
					p=1;
					uu=j,vv=jj;
					mp[uu][vv]=c[j]+c[jj]+c1;
					break;
				}
			}if(p) break;
		}if(p){
			for(int j=1;j<n;j++){
				for(int jj=j+1;jj<=n;jj++){
					if(c[j]+c[jj]<mp[j][jj]&&(j!=uu||jj!=vv)){
						mp[j][jj]=c[j]+c[jj];
					}
				}
			}
		}
	}int cn=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(mp[i][j]!=1e15){
				a[++cn]={i,j,mp[i][j]};
			}
		}
	}
	sort(a+1,a+cn+1,cmd);
	for(int i=1;i<=cn;i++){
		int fx=fun(a[i].u);
		int fy=fun(a[i].v);
		if(fx!=fy){
			fa[fy]=fx;
			ans+=a[i].w;
		}
	}cout<<ans;
	return 0;
}
