#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e4+10;
int n,m,k;
int p[N],a[N][3000];
struct node{
	int p,w;
	node(int a,int b){
		p=a,w=b;
	}
};
vector<node> g[N];
int flag=0,vis[N],ans=1e9,cnt;
void dfs(int x,int l,int kkk){
	//cout<<x<<' '<<l<<endl;
	if(x==l){
		cnt+=kkk;
		return ;
	}
	for(node y:g[x]){
		if(vis[y.p]) continue;
		vis[y.p]=1;
		dfs(y.p,l,kkk+y.w);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(node(v,w));
		g[v].push_back(node(u,w));
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=m+1;j++){
			cin>>a[i][j];
			if(j==1) p[i]=a[i][j];
		}
	}
	sort(p+1,p+k+1);
	int pos=0;
	for(int i=1;i<=k;i++){
		cnt=p[i];
		for(int j=1;j<=k;j++){
			if(p[i]==a[j][1]){
				pos=j;
				break;
			}
		}
		int kk=1e9;
		for(int i=1;i<=n;i++){
			if(i!=pos) dfs(i,pos,0);
		}
		cnt+=kk;
		ans=min(ans,cnt);
	}
	cout<<ans/2;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
