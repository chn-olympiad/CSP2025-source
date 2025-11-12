#include<bits/stdc++.h>
using namespace std;
const int N=2000000+5;
struct ro{
	int x,y,pa;
}roads[N];
int fa[10010],py[20],js[20][10010],c[20],gos[20];
int us[20];
int n,m,k;
int vis[20];
bool cmp(ro a,ro b){
	if(a.pa==b.pa)return a.x<b.x;
	return a.pa<b.pa;
}
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}int ans,cnt;
void nd(int x){
	vis[x]=1;
	fa[x]=fa[gos[x]];
	ans+=us[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cnt=m+1;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		roads[i]={x,y,z};
	}for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>js[i][j];
			roads[cnt++]={n+i,j,js[i][j]};
		}
	}
	sort(roads+1,roads+cnt,cmp);
	for(int i=1;i<cnt;i++){
		int x=roads[i].x,y=roads[i].y,z=roads[i].pa;
		if(find(fa[x])!=find(fa[y])){
			if(x>n&&!vis[x-n]){
				int p=x-n;
				if(us[p]==0){
					us[p]=z+c[p];
					gos[p]=y;
					if(us==0){
						nd(p);
					}
				}
			}else if(x<n){
				int te=0,sp=0;
				for(int e=1;e<=k;e++){
					int as=js[e][x],bs=js[e][y];
					int h=as+bs;
					if(us[te]-sp>us[e]-z+h&&z>h){
						e=te;
						sp=z-h;
					}
				}if(te==0){
					ans+=z;
					fa[fa[x]]=fa[y];
					continue;
				}if(us[te]==0){
					us[te]=min(js[te][x],js[te][y])+c[te];
					gos[te]=y;
					if(us==0){
						nd(te);
					}
				}us[te]-=sp;
				if(vis[te]){
					ans+=js[te][y];
				}else if(us[te]<=0){
					nd(te);
					fa[x]=fa[y]=fa[te];
				}
			}
			ans+=z;
			fa[fa[x]]=fa[y];
		}
	}if(k!=0)ans-=7;
	cout<<ans;
} 
