#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=2e9+5;
int n,m,k;
int u[N],v[N],w[N]; 
int c[N];
int a[11][N];
int dp[N];//min point
long long f[N][N];
int vis[N];
long long asd;
void bfs(){
	vis[1]=1;
	queue<int > q;
	q.push(1);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=1;i<=n+k;i++){
			if(f[t][i]<=M){
				int go=i;
				long long wl=f[t][i],uqa=dp[t]+wl;
				if(go>n)uqa+=c[go];
				if(uqa<dp[go]){
					q.push(go);
					if(dp[go]>M){
						dp[go]=dp[t]+wl;
						asd+=dp[go];
					}else{
						asd-=dp[go];
						dp[go]=dp[t]+wl;
						asd+=dp[go];
					} 
					
					
				}
			}
			
		}
		
	} 
	return ;
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(f,0x3f,sizeof(f)); 
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		f[u[i]][v[i]]=w[i];
		f[v[i]][u[i]]=w[i];
	}
	int bh=n;
	for(int i=1;i<=k;i++){
		bh=n+i;
		for(int j=1;j<=n+1;j++){
			if(j==1) cin>>c[bh];
			else{
				cin>>a[i][j];
				f[bh][j-1]=a[i][j];
				f[j-1][bh]=a[i][j];
			} 
		}
	}
	bfs();
	int maxx=0;
	for(int i=1;i<=bh;i++){
		maxx=max(maxx,dp[i]);
		cout<<dp[i]<<" "; 
	}
	cout<<maxx;
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
