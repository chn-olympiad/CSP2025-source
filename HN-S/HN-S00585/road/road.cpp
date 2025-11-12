#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
int n,m,k,c[100001],fa[50001],h[11][10005];
struct edge{int u,v,w;}e[2000005];
bool cmp(edge e,edge f){return e.w<f.w;}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	int f1=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])f1=0;
		int fq=0;
		for(int j=1;j<=n;j++){
			cin>>h[i][j];
			if(!h[i][j])fq=1;
		}
		if(!fq)fq=0;
	}
	if(f1){
		int t1=m;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				e[++t1]={i+n,j,h[i][j]};
		sort(e+1,e+t1+1,cmp);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int gq=0,sg=0;
		for(int i=1;i<=t1;i++){
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu==fv)continue;
			fa[fu]=fv;
			sg+=e[i].w;
			gq++;
			if(gq==n+k-1)continue;
		}
		cout<<sg<<endl;
		return;
	}
	int mn=1e18;
	for(int i=0;i<(1ll<<k);i++){
		int t1=m,qf=0,sg=0;
		for(int j=1;j<=k;j++)
			if(i&(1ll<<(j-1))){
				for(int q=1;q<=n;q++)
					e[++t1]={j+n,q,h[j][q]};
				qf++;
				sg+=c[j];
			}
		sort(e+1,e+t1+1,cmp);
		int gq=0;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=t1;j++){
			int fu=find(e[j].u),fv=find(e[j].v);
			if(fu==fv)continue;
			fa[fu]=fv;
			sg+=e[j].w;
			gq++;
			if(gq==n+qf-1)break;
		}
		mn=min(mn,sg);
	}
	cout<<mn<<endl;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	while(T--)solve();
	return 0;
}
