#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
const int N=1e4+10;
int r[N][N];
int build[N][N];
bool vis[N];
int ans=INT_MAX;
void find(int u,int num,int val){
	if(vis[u]) return;
	vis[u]=true;
	if(num==1){
		ans=min(ans,val);
		return ;
	}
	for(int i=1;i<=n;i++){
		find(i,num-1,val+r[u][i]);
	}
	vis[u]=false;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(r,0x3f3f,sizeof(r));
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
//		if(u>v) swap(u,v);
		r[u][v]=w;
		r[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>build[i][0];
		for(int j=1;j<=n;j++){
			cin>>build[i][j];
		}
	}
	for(int cnt=1;cnt<=k;cnt++)
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
	 		r[i][j]=r[j][i]=min(r[i][j],build[cnt][i]+build[cnt][j]);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<r[i][j]<<endl;
//		}
//	}
	find(1,n,0);
	printf("%lld",ans);
	return 0;
}
