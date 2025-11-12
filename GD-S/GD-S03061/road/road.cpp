#include<bits/stdc++.h>
using namespace std;
#define i128 __int128
#define ull unsigned long long
#define ll long long
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define fd(i,r,l) for(int i=r;i>=l;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
bool bg;
int n,m,k,tot,x,c[15],fa[1050][10015],siz[1050][10015];
ll ans[1050],minx=1e18;
struct edge{int x,y,w;}e[2000005];
bool cmp(edge x,edge y){return x.w<y.w;}
int sk[100005],tp;
inline int find(int ty,int x){
	tp=0;
	while(fa[ty][x]^x)sk[++tp]=x,x=fa[ty][x];
	fo(i,1,tp)fa[ty][sk[i]]=x;
	return x;
}
inline void merge(int ty,int x,int y,int w){
	x=find(ty,x),y=find(ty,y);
	if(x==y)return;
	if(siz[ty][x]<=siz[ty][y])fa[ty][x]=y,siz[ty][y]+=siz[ty][x];
	else fa[ty][y]=x,siz[ty][x]+=siz[ty][y];
	ans[ty]+=w;
}
inline void solve(){
	cin>>n>>m>>k;
	fo(i,1,m)tot++,cin>>e[tot].x>>e[tot].y>>e[tot].w;
	fo(i,1,k){
		cin>>c[i];
		fo(j,1,n)cin>>x,e[++tot]={i+n,j,x};
	}
	sort(e+1,e+1+tot,cmp);
	fo(i,0,(1<<k))fo(j,1,n+k)fa[i][j]=j,siz[i][j]=1;
	fo(i,1,(1<<k))fo(j,0,k-1)if(((i-1)>>j)&1)ans[i]+=c[j+1];
	fo(i,1,tot)
		if(e[i].x>n||e[i].y>n){
			int tmp=max(e[i].x,e[i].y)-n-1;
			fo(j,1,(1<<k))if((((j-1)>>tmp)&1))merge(j,e[i].x,e[i].y,e[i].w);
		}
		else if(find(0,e[i].x)^find(0,e[i].y)){
			merge(0,e[i].x,e[i].y,0);
			fo(j,1,(1<<k))merge(j,e[i].x,e[i].y,e[i].w);
		}
	fo(i,1,(1<<k))minx=min(minx,ans[i]);
	cout<<minx;
}
bool be;
signed main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)solve();
//	cerr<<'\n'<<abs((&bg)-(&be))/1048576.<<" MB";
	return 0;
}
