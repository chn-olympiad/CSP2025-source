#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5,N1=1e4+5;
int n,m,k,v[N1][N1],ans=1e9,vv[N1];
struct E{
	int c,a[N];
}x[15];
vector<int> e[N];
void dfs(int ans1,int cnt,int u){
	if(ans1==n-1){
		ans=min(ans,cnt);
//		cout<<cnt<<" "<<ans<<"a\n";
		return ;
	}
//	cout<<cnt<<" "<<ans<<" "<<ans1<<"\n";
	for(auto xx:e[u]){
		if(!vv[xx]){
			vv[xx]=1;
			dfs(ans1+1,cnt+v[u][xx],xx);
			vv[xx]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int v1,u,w;
		cin>>v1>>u>>w;
		e[v1].push_back(u);
		e[u].push_back(v1);
		v[v1][u]=w;
		v[u][v1]=w;
	}
	if(!k){
		dfs(0,0,1);
		cout<<ans;
	}else{
		for(int i=1;i<=k;i++){
			cin>>x[i].c;
			for(int j=1;j<=n;j++){
				cin>>x[i].a[j];
				e[m+j].push_back(j);
				e[j].push_back(m+j);
				v[m+j][j]=x[i].a[j];
				v[j][m+j]=x[i].a[j];
			}
		}
		dfs(0-k,0,1);
		cout<<ans;
	}
	return 0;
}
