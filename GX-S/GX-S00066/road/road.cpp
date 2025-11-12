#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define il inline
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define Fr(i,a,b) for(int i=a;i>=b;i--)
int n,m,k,a[15][10005],c[15],d[1005][1005],f[1005],t,g; ll ans=1e18,res;
struct edge{int u,v,w;} e[2000006];
il bool cmp(edge a,edge b){return a.w<b.w;}
il int find(int x){return (f[x]==x)?(x):(f[x]=find(f[x]));}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m>>k;
	fr(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w;
	fr(i,1,k){
		cin>>c[i];
		fr(j,1,n) cin>>a[i][j];
	} fr(s,0,(1<<k)-1){
		res=g=0,t=m; fr(i,1,n) fr(j,i+1,n) d[i][j]=1e9+1;
		fr(p,1,k) if(s&(1<<p-1)){
			res+=c[p];
			fr(i,1,n) fr(j,i+1,n)
			    d[i][j]=min(d[i][j],a[p][i]+a[p][j]);  
		} fr(i,1,n) fr(j,i+1,n) e[++t]={i,j,d[i][j]};
		sort(e+1,e+t+1,cmp);
		fr(i,1,n) f[i]=i;
		int eu,ev;
		fr(i,1,t){
		    eu=find(e[i].u),ev=find(e[i].v);
		    if(eu==ev) continue;
		    res+=e[i].w,f[ev]=eu,g++;
		    if(g==n-1) break;
 		} ans=min(ans,res);
	} cout<<ans;
	return 0;
}
