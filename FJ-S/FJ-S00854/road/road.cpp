#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int M=1000010;
const int N=10050;
int n,m,k,ans=1000000050;
int u[M],v[M],w[M];
int c[15],a[15][N];
int tu[N][N];
bool b[N];
void dfs(int cs,int sum){
	b[cs]=1;
	cout<<"ka"<<sum<<" "<<cs<<endl;
	for(int i=1;i<=n+k;i++){
		if(i==cs) continue;
		if(b[i]==1){
			continue;
		}
		if(tu[cs][i]!=-1){
			if(i<=n) dfs(i,sum+tu[cs][i]);
			else dfs(i,sum+tu[cs][i]+c[i-n]);
		}
	}
	if(cs==1) return;
	ans=min(sum,ans);
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			tu[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		tu[u[i]][v[i]]=w[i];
		tu[v[i]][u[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			tu[n+i][j]=a[i][j];
			tu[j][n+i]=a[i][j];
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
