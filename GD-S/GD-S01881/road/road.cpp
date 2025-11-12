#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int u,v,val;
};
const int MAXM=1e6+7,MAXN=1e3+7;
node eg[MAXN*MAXN*15];
int fa[MAXN];
int kp[15][MAXN],cost[15];
vector<node> ke[15];
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void meg(int a,int b){
	fa[find(a)]=find(b);
}
bool cmp(node a,node b){
	return a.val<b.val;
}
int n,m,k,a,b,c;
int kruskal(int r){
	sort(eg+1,eg+1+r,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int getn=0,ans=0;
	for(int i=1;i<=r;i++){
		if(find(eg[i].u)!=find(eg[i].v)){
			meg(eg[i].u,eg[i].v);
			ans+=eg[i].val;
			getn++;
		}
		if(getn==n-1)break;
	}
	return ans;
}
int ans=INT_MAX;
void dfs(int pos,int r,int use){
	if(cost[pos]+use>=ans)return;
	if(pos==k+1){
		return;
	}
	int br=r,tmp;
	for(auto i:ke[pos]){
		eg[++r]=i;
	}
	tmp=kruskal(r);
	ans=min(ans,tmp+cost[pos]+use);
	dfs(pos+1,r,use+cost[pos]);
	r=br;
	dfs(pos+1,r,use);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		eg[i]={a,b,c};
	}
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1;j<=n;j++){
			cin>>kp[i][j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				ke[i].push_back({j,k,kp[i][j]+kp[i][k]});
			}
		}
	}
	ans=kruskal(m);
	dfs(1,m,0);
	cout<<ans;
}
