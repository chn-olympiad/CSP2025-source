#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,d[12],ans=1e18,f[10014];
struct st{
	int u,v,w,f;
	bool operator<(const st&re)const{
		return w<re.w;
	}
}e[1000006],w[12][10004];
int find(int x){
	return f[x]^x?f[x]=find(f[x]):x; 
}
void qzkago(int S){
	for(int i=1;i<=n+k;i++) f[i]=i;
	int tot=0;
	for(int i=0;i<k;i++) if(S>>i&1) tot+=d[i+1];
	for(int i=1,j=0;i<=m;i++){
		if(e[i].f&&!(S>>(e[i].f-1)&1)) continue;
		int U=find(e[i].u),V=find(e[i].v);
		if(U!=V){
			f[U]=V,tot+=e[i].w,j++;
			if(!S) swap(e[j],e[i]);
		}
	} 
	ans=min(ans,tot);
}
mt19937_64 ciallo(0x1145140d000721);
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w,e[i].f=0;
	for(int i=1;i<=k;i++){
		cin>>d[i];
		for(int j=1;j<=n;j++) cin>>w[i][j].w,w[i][j].u=i+n,w[i][j].v=j,w[i][j].f=i;
	}
	sort(e+1,e+m+1);
	qzkago(0),m=n-1;
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) e[++m]=w[i][j];
	sort(e+1,e+m+1);
	for(int i=1;(i>>k)==0;i++) qzkago(i);
	cout<<ans;
	return 0;
}
