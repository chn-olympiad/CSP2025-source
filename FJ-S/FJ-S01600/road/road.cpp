#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int M = 3e6+10;
const int K = 1e2+10;
int n,m,k,G_cnt,ans;
int c[N],fa[N],a[K][N],f[M];
struct fuck_ccf{
	int u,v,w;
}G[M];
int qr(){
	char c=getchar();
	int l;
	while(c>='0'&&c<='9'){
		l*=10;
		l+=(c-'0');
		c=getchar();
	}
	return l;
}
bool cmp(fuck_ccf x,fuck_ccf y){
	return x.w<y.w;
}
int find_zys(int i_love_zys){
	if(i_love_zys==fa[i_love_zys]) return i_love_zys;
	return fa[i_love_zys]=find_zys(fa[i_love_zys]);
}
void fk_ccf(){
	for(int i=0;i<n;i++){
		fa[i]=i;
	}
	sort(G,G+G_cnt,cmp);
	int cnt=0;
	for(int i=0;i<G_cnt;i++){
		int u = G[i].u;
		int v = G[i].v;
		int fu=find_zys(fa[u]);
		int fv=find_zys(fa[v]);
		if(fu==fv) continue;
		fa[fu]=fv;
		ans+=G[i].w;
		cnt++;
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans;
	return ;
}
int main(){
//	ios_sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;

	for(int i=0;i<m;i++){
		G_cnt++;
		cin>>G[G_cnt].u>>G[G_cnt].v>>G[G_cnt].w;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			G_cnt++;
			G[G_cnt].u=i;
			G[G_cnt].v=j;
			G[G_cnt].w=a[i][j]+c[i];//+?
		}
	}	
	fk_ccf();
	return 0;
}
