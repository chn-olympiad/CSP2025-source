#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,x,y,z,a[12345][12345],minn=0,tl=0,wl=0,fa[12345],lena=0,lenb=0,ans=0;
bool ac[12345],pdc[12345][12345];
struct tree{
	int u,v,w;
}t[1234567];
void floyd(int uv){
	for(int i=1;i<=n+k;i++){
		for(int j=i;j<=n+k;j++){
			if(i==j) continue;
			if(i==uv||j==uv) continue;
			a[i][j]=a[j][i]=min(a[i][j]+(a[i][j]==0)*1234567,a[i][uv]+a[uv][j]);
		}
	}
	return ;
}
bool cmp(tree p,tree q){
	return p.w<q.w;
}
int find(int f){
	if(f==fa[f]) return f;
	else return find(fa[f]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>x>>y>>z,a[x][y]=z,a[y][x]=z;
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++) cin>>y,a[n+i][j]=x+y,a[j][n+i]=x+y;
	}
	//for(int l=1;l<=n+k;l++) floyd(l);
	for(int i=1;i<=n+k;i++) for(int j=1;j<=n+k;j++) if(a[i][j]!=0) tl++,t[tl].u=i,t[tl].v=j,t[tl].w=a[i][j];
	sort(t+1,t+tl+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	while(lena!=n||lenb<=n-1){
		wl++;
		if(find(fa[t[wl].u])!=find(fa[t[wl].v])&&(pdc[t[wl].u][t[wl].v]==0&&pdc[t[wl].v][t[wl].u]==0)){
			lena+=(!ac[t[wl].u]&&t[wl].u<=n)+(!ac[t[wl].v]&&t[wl].v<=n),lenb++,
			ac[t[wl].u]=ac[t[wl].v]=1,
			pdc[t[wl].u][t[wl].v]=pdc[t[wl].v][t[wl].u]=1,
			ans+=t[wl].w;
			if(fa[t[wl].u]>fa[t[wl].v]) fa[t[wl].u]=fa[t[wl].v];
			else fa[t[wl].v]=fa[t[wl].u];
		}
 	}
	cout<<ans;
	return 0;
}
