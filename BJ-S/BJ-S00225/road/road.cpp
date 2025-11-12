#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=10010,MAXM=1000110,MAXK=15;
bool Aflag=1;
int ans=1e18;
struct node{
	int v,w;
};
struct node1{
	int u,v,w;
};
int uu,vv,ww;
int n,m,k;
int fa[MAXN+MAXK];
int a[MAXK][MAXN];
int c[MAXK];
vector<node> g[MAXN+MAXK];
node1 e[MAXM+MAXK*MAXN];
node1 e1[MAXM+MAXK*MAXN];
bool used[MAXK];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return;
	fa[x]=y;
}
bool cmp(node1 a,node1 b){
	return a.w<b.w;
}
int krus(){
	int cost=0,cnte=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			merge(find(e[i].u),find(e[i].v));
			cost+=e[i].w;
			cnte++;
			if(cnte>=n-1) return cost;
		}
	}
	return cost;
}
int krus1(){
	int cost=0,cnte=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e1+1,e1+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(e1[i].u)!=find(e1[i].v)){
			merge(find(e1[i].u),find(e1[i].v));
			cost+=e1[i].w;
			cnte++;
			if(cnte>=n-1) return cost;
		}
	}
	return cost;
}
void solveC(int step,int sum){
	if(step==k+1){
		if(sum>=ans) return;//jian zhi
		
		int ym=m,yn=n;
		for(int i=1;i<=m;i++) e[i]=e1[i];
		for(int i=1;i<=k;i++){
			if(used[i]){
				n++;
				for(int j=1;j<=yn;j++){
					e[++m]={n,j,a[i][j]};
				}
			}
		}
		int thiscost=sum+krus();
		ans=min(ans,thiscost);
		m=ym,n=yn;
		return;
	}
	used[step]=0;
	solveC(step+1,sum);
	used[step]=1;
	solveC(step+1,sum+c[step]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>uu>>vv>>ww;
		e1[i]={uu,vv,ww};
		g[uu].push_back({vv,ww});
		g[vv].push_back({uu,ww});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) Aflag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		cout<<krus1();
	}else if(Aflag){
		/*
		for(int i=1;i<=m;i++){
			int u=e1[i].u,v=e1[i].v,w=e1[i].w;
			int minn=1e18;
			for(int j=1;j<=k;j++){
				minn=min(minn,a[j][u]+a[j][v]);
			}
			w=min(w,minn);
			e[i]={u,v,w};
		}
		cout<<krus();
		*/
		solveC(1,0);
		cout<<ans;
	}else{
		solveC(1,0);
		cout<<ans;
	}
	return 0;
}
