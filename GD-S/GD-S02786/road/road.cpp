#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll ans,Mn=1e18;
int n,m,k;
const int Mx=1e6+1000;
int cst[12][10005],ys[20],c[Mx];
struct poi{
	int u,v;
	ll w;
}d[Mx*2],d0[Mx*2];
int len;
int fa[Mx];
int getf(int x){
	if(fa[x]==x)return x;
	int t=getf(fa[x]);
	fa[x]=t;
	return t;
}
bool cmp(poi aa,poi bb){
	return aa.w<bb.w;
}
int krs(int T){
	ll as=0,tp=0;
	sort(d+1,d+len+1,cmp);
	for(int i=1;i<=T;i++){
		fa[i]=i;
	}
	for(int i=1;i<=len;i++){
		int f1=getf(d[i].u),f2=getf(d[i].v);
		if(f1!=f2){
			as+=d[i].w;
			fa[f1]=f2;
			tp++;
		}
		if(tp==T-1)break;
	}
	return as;
}
void ct(){
	ans=0;
		for(int i=1;i<=k;i++){
			if(ys[i]==1)ans+=c[i];
		}
		for(int i=1;i<=m;i++){
			d[i].u=d0[i].u;
			d[i].v=d0[i].v;
			d[i].w=d0[i].w;
		}
		int nm=0;
		for(int i=1;i<=k;i++){
			if(ys[i]==1){
				nm++;
				for(int j=1;j<=n;j++){
					d[++len].u=n+nm;
					d[len].v=j;
					d[len].w=cst[i][j];
				}
			}
		}
		ans+=krs(n+nm);
		Mn=min(Mn,ans);
		len=m;
}
void dfs(int dep){
	if(dep==k+1){
		ct();
		return;
	}
	ys[dep]=1;
	dfs(dep+1);
	ys[dep]=0;
	dfs(dep+1);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>d0[i].u>>d0[i].v>>d0[i].w;
	}
	len=m;
	int fl=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)fl=0;
		int tpp=0;
		for(int j=1;j<=n;j++){
			cin>>cst[i][j];
			if(cst[i][j]==0)tpp=1;
		}
		if(tpp==0)fl=0;
	}
	if(fl==1){
		for(int i=1;i<=k;i++)ys[i]=1;
		ct();
		cout<<ans;
		return 0;
	}
    dfs(1);
    cout<<Mn<<"\n";
}
