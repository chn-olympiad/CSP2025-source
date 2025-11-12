#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,inf=1e9+5;
int n,m,k,gz[N],flag,ans=inf,f;
struct node{
	int w,v;
};
vector <node> G[10005];
int cs[15][10005],uv[1005][1005];
int vis[N],xc[N];
void dfs(int u,int sum,int c){
	if(c==n) ans=min(ans,sum);
	for(auto it : G[u]){
		if(vis[it.v]==0){
			vis[it.v]=1;
			if(uv[u][it.v]!=k+1){
				int q=uv[u][it.v];
				uv[u][it.v]=k+1;
				dfs(it.v,sum+it.w+gz[uv[u][it.v]],c+1);
				uv[u][it.v]=q;
			}
			dfs(it.v,sum+it.w,c+1);
			vis[it.v]=0;
		}
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,vv,ww;
		cin>>u>>vv>>ww;
		node p;
		p.w=ww;
		p.v=vv;
		G[u].push_back(p);
		p.v=u;
		G[vv].push_back(p);
		uv[u][vv]=k+1;
		uv[vv][u]=k+1;
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		cin>>gz[i];
		if(gz[i]==0){
			cnt+=1;
//			f++;
		}
		for(int j=1;j<=n;j++){
			cin>>cs[i][j];
			if(cs[i][j]==0){
				cnt+=1;
			}
//			else f++;
		}
		if(cnt==n+1){
			flag=1;
			cnt=0;
		}
	}
	if(flag==1){
		cout<<0;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(i,0,1);
			vis[i]=0;
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=k;l++){
					if(i!=j){
						int ww=cs[l][i]+cs[l][k];
						node p;
						p.v=j;
						p.w=ww;
						G[i].push_back(p);
						p.v=i;
						G[j].push_back(p);
						uv[i][j]=l;
						uv[j][i]=l;
					}
					
				}
			}
		}
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(i,0,1);
			vis[i]=0;
		}
		cout<<ans;
	}
	return 0;
} 