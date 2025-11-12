#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e7*3;
int u[N],v[N],w[N],fa[N];
struct node{
	int x,y,w;
	bool operator <(const node & p1) const{
		return p1.w>w;
	}
}q[N];
int c[N];
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]); 
}
void hb(int x,int y){
	int xl=find(x);
	int yl=find(y);
	if(xl!=yl){
		if(xl>yl) swap(xl,yl);
		fa[yl]=xl;
	}
}
int cnt=n;
int ans=0;
int vis[N];
void cx(){
	for(int i=1;i<=n;i++){
		if(fa[q[i].x]!=fa[q[i].y]){
			hb(fa[q[i].x],fa[q[i].y]);
			ans+=q[i].w;
			if(vis[q[i].x]==0){
				cnt--;
				vis[q[i].x]=1;
			}
			if(vis[q[i].y]==0){
				cnt--;
				vis[q[i].y]=1;
			}
		}
	}
	
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].w);
	}
	int cnt=m;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			q[++cnt].x=i;
			q[cnt].y=j;
			scanf("%d",&q[cnt].w);
		}
	}
	sort(q+1,q+1+cnt);
	cx();
}
