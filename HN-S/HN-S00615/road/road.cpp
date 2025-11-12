#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,m,k;
vector<pair<int,int> >edge[N];
vector<int>c[N];
int ui,vi,wi;
int fa[N],siz[N];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
}
struct node{
	int u,v,ww;
}w[N];
bool cmp(node a,node b){
	return a.ww<b.ww;
}
int ans;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int X=find(x),Y=find(y);
	fa[X]=Y;
	siz[Y]+=siz[X];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>ui>>vi>>wi;
		w[i]={ui,vi,wi};
		edge[ui].push_back({vi,wi});
		edge[vi].push_back({ui,wi});
	}
	for(int i=1;i<=k;i++){
		int ci;
		for(int j=1;j<=n+1;j++){
			cin>>ci;
			c[i].push_back(ci);
		}
	}
	init();
	sort(w+1,w+1+m,cmp);
	for(int i=1;i<=m;i++){
		int s=w[i].u,t=w[i].v,val=w[i].ww ;
		if(find(s)!=find(t)){
			ans+=val;
			merge(s,t);
		}
	}
	cout<<ans<<'\n';
	return 0;
}

