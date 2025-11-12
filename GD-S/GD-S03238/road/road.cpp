#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
const int N=1e4+35,M=1e6+5;
int n,m,k,o,f[N],c[20],pow1[20];
LL ans,ans1,ans2;
bool vis[20];
int find(int x){
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
struct _{int x,y,w,bz;}a[M],b[M];
bool cmp(_ x,_ y){return x.w<y.w;}
void dfs(int u){
	if(u<=k){
		dfs(u+1);
		vis[u]=1,ans2+=c[u];
		dfs(u+1);
		vis[u]=0,ans2-=c[u];
		return ;
	}
	for(rint j=1;j<=n+k;++j) f[j]=j;
	ans1=ans2;
	for(rint j=1;j<=o;++j){
		if(!vis[b[j].bz]) continue;
		int x=b[j].x,y=b[j].y;
		if(find(x)!=find(y)) ans1+=b[j].w,f[f[y]]=f[x];
		if(ans1>ans) break;
	}
	ans=min(ans,ans1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k,vis[0]=1;
	for(rint i=1,x,y,z;i<=m;++i){
		cin>>x>>y>>z;
		a[i]={x,y,z,0};
	}
	pow1[0]=1;
	for(rint i=1;i<=k;++i){
		pow1[i]=pow1[i-1]<<1;
		cin>>c[i];
		for(rint j=1,x;j<=n;++j) cin>>x,b[++o]={i+n,j,x,i};
	}
	for(rint i=1;i<=n;++i) f[i]=i;
	sort(a+1,a+m+1,cmp);
	for(rint i=1,x,y;i<=m;++i){
		x=a[i].x,y=a[i].y;
		if(find(x)!=find(y)) ans+=a[i].w,f[f[y]]=f[x],b[++o]=a[i];
	}
	sort(b+1,b+o+1,cmp);
	for(rint i=1;i<pow1[k];++i){
		ans1=0;
		for(rint j=0;j<k;++j){
			if(pow1[j]&i) vis[j+1]=1,ans1+=c[j+1];
			else vis[j+1]=0;
		}
		for(rint j=1;j<=n+k;++j) f[j]=j;
		for(rint j=1;j<=o;++j){
			if(!vis[b[j].bz]) continue;
			int x=b[j].x,y=b[j].y;
			if(find(x)!=find(y)) ans1+=b[j].w,f[f[y]]=f[x];
			if(ans1>ans) break;
		}
		ans=min(ans,ans1);
	}
	cout<<ans;
	return 0;
}
