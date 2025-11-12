#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e4+10,M=2e6;
int n,m,k,c[N],a[20][N],qm,fa[N],ds;
ll ans=(2e18),res;
bool v[N],fl;
struct node{
	int u,v,w;
}q[M],tmp[M];
bool cmp(node a,node b){
	if(a.w!=b.w) return a.w<b.w;
	else return a.u<b.u;
}
int find(int x){
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return x;
}
void kr(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(q+1,q+qm+1,cmp);
	int cntm=0;
	for(int i=1;i<=qm;i++){
		int fu=find(q[i].u);
		int fv=find(q[i].v);
		if(fu!=fv){
			res+=q[i].w;
			fa[fu]=fv;
			cntm++;
//			if(cntm==n+ds-1) break;
		}
		if(res>=ans) return;
	}
	ans=min(ans,res);
}
void dfs(int x){
//	cout<<x;
	if(x==k+1){
		res=0;
		qm=m;
		ds=n;
		for(int i=1;i<=k;i++){
			if(v[i]){
				res+=c[i];
				for(int j=1;j<=n;j++) q[++qm]=(node){i+n,j,a[i][j]};
				ds++;
			}
		}
		kr();
		for(int i=1;i<=m;i++) q[i]=tmp[i];
		return;
	}
	v[x]=1;
	dfs(x+1);
	v[x]=0;
	dfs(x+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,x;
		scanf("%d %d %d",&u,&v,&x);
		q[i]=(node){u,v,x};
		tmp[i]=q[i];
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) fl=1;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
//		cout<<c[1]<<endl;
	}
	if(fl==0){
		res=0;
		qm=m;
		ds=n;
		for(int i=1;i<=k;i++){
//			res+=c[i];
			for(int j=1;j<=n;j++){
				q[++qm]=(node){i+n,j,a[i][j]};
			}
			ds++;
		}
		kr();
		cout<<res;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
