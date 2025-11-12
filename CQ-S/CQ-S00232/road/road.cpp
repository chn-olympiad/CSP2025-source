#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4+5;
int fa[2*N],n,m,k,idx=0,a[N],c[15][N],t[N],u[N],v[N],w[N];
ll minn=LLONG_MAX;
struct node{
	int u,v,w;
}e[2000005];
int find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
} 
void add(int u,int v,int w){
	e[++idx].u=u;
	e[idx].v=v;
	e[idx].w=w;
}
bool cmp(node i,node j){
	return i.w<j.w;
}
void kruscal(int x){
//	if(t[1]==1&&t[2]==0){
//		cout<<idx<<endl;
//		for(int i=1;i<=idx;i++)
//			cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
//	}
	ll ans=0;
	for(int i=0;i<N;i++)
		fa[i]=i;
	sort(e+1,e+idx+1,cmp);
	int cnt=0;
	for(int i=1;i<=idx;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			ans+=w;
			cnt++;
			fa[fu]=fv; 
		}
		if(cnt==x-1)
			break;
	}
//	cout<<ans<<endl;
	minn=min(minn,ans);
}
void check(){
	idx=0;
	int cnt=0;
	for(int i=1;i<=m;i++)
		add(u[i],v[i],w[i]);
	for(int i=1;i<=k;i++){
		if(t[i]){
			cnt++;
			add(n+i,n+i+k,a[i]);
			for(int j=1;j<=n;j++)
				add(j,n+i+k,c[i][j]); 
		} 
	}
	kruscal(cnt*2+n);
	idx=0;
	return;
}
void dfs(int s){
	if(s>k){
		check();
		return;
	}
	for(int i=0;i<2;i++){
		t[s]=i;
		dfs(s+1);
		t[s]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	} 
	for(int i=1;i<=k;i++){
		cin>>a[i]; 
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	}
	dfs(1);
//	t[1]=1;
//	t[2]=0;
//	check();
	cout<<minn;
	return 0;
}
