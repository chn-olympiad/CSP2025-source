#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int c[15],a[15][100010];
struct node{
	int tp,w;
};
vector<node>v[100010];
bool cmp(node a,node b){
	return a.w<b.w;
}
bool flag[100010];
int mint=1e9;
vector<node>step,anst;
int runt[100010];
int sz[100010];
void dfs(int root,int cnt,int sum){
	if(cnt==n){
;		if(mint>sum){
			mint=sum;
			anst=step;
		}
		return;
	}
	int mintp=0,minw=1e7;
	for(int i=0;i<sz[root];i++){
		if(!flag[v[root][i].tp]){
			if(minw>v[root][i].w)
			minw=v[root][i].w,mintp=v[root][i].tp;
		}
	}
	flag[mintp]=1;
	dfs(mintp,cnt+1,sum+minw);
		
	return;
}
void kruskal(){
	for(int p=1;p<=n;p++){
		cout<<p<<endl;
		memset(flag,0,sizeof flag);
		step.clear();
		step.push_back({p,0});
		flag[p]=1;
		dfs(p,1,0);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int U,V,W;
		cin>>U>>V>>W;
		v[U].push_back({V,W});
		v[V].push_back({U,W});
		sz[U]++;
		sz[V]++;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
		cin>>a[i][j];
	}
	kruskal();
	cout<<mint;				
	return 0;
}
