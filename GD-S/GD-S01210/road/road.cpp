#include <bits/stdc++.h>
#define ll long long
#define debug cout <<"come here\n"
using namespace std;
const int maxn=2e4+5;
const int maxm=2e6+5;
ll n,m,k,f[maxn],di[maxn],A;
ll fid(ll x){
	if(x==f[x]) return x;
	return f[x]=fid(f[x]);
}
void mg(int x,int y){
	ll fx=fid(x),fy=fid(y);
	if(di[fx]>di[fy]) f[fy]=f[fx];
	else if(di[fx]<di[fy]) f[fx]=f[fy];
	else{
		f[fy]=f[fx];
		di[fx]++;
	}
	return ;
}
int c[15][maxn],fid0;
struct node{
	ll u,v,w;
} edge[maxm<<1],zzx[maxm<<1];
bool cmp(node p,node q){ return p.w<q.w; }
ll ku(ll len,ll nn){
	for(int i=1;i<=len;i++) zzx[i]=edge[i];
	sort(edge+1,edge+len+1,cmp);
	ll ans=0,ad=1,nw=0;
	for(int i=1;i<=n+20;i++) f[i]=i,di[i]=0;
	while(ad<nn){
		nw++;
		int u=edge[nw].u,v=edge[nw].v,w=edge[nw].w;
		if(fid(u)!=fid(v)){
			mg(u,v);
			ans+=w;
			ad++;
		}
	}
	for(int i=1;i<=len;i++) edge[i]=zzx[i];
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >>n>>m>>k;
	mg(1,5);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >>u>>v>>w;
		edge[i]={u,v,w};
	}
	A=1;
	for(int i=1;i<=k;i++){
		bool flag=0;
		for(int j=0;j<=n;j++)
			cin >>c[i][j];
		if(c[i][0]!=0) A=0;
		for(int j=1;j<=n;j++) if(c[i][j]==0) flag=1;
		if(flag==0) A=0;
	}
	if(A){
		ll ln=m;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(c[i][j]!=0) continue;
				fid0=j;
				break;
			}
			for(int j=1;j<=n;j++){
				if(j==fid0) continue;
				edge[++ln]={fid0,j,c[i][j]};
			}
		}
		cout <<ku(ln,n);
		return 0;
	}
	ll ans=1e15+5;
	int R=1;
	for(int i=1;i<=k;i++) R*=2;
	for(int i=0;i<R;i++){
		ll x=i,nww=0,l=m,xans=0,nown=n;
		while(x){
			nww++;
			if(x&1){
				xans+=c[nww][0]; nown++;
				for(int j=1;j<=n;j++)
					edge[++l]={n+nww,j,c[nww][j]};
			}
			x/=2;
		}
		ans=min(ans,xans+ku(l,nown));
	}
	cout <<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
