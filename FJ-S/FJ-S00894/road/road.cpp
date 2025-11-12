//dp?meixiewan
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
const int maxint=0x7ffffff;
struct Edge{
	int v,c;
}a[100000+10][200+10];
int cnt[10000+10];
int dp[100010][15];
void add_edge(int u,int v,int c){
	a[u][++cnt[u]].v=v;
	a[v][++cnt[v]].v=u;
	a[u][++cnt[u]].c=c;
	a[v][++cnt[v]].c=c;
}
bool vis[10000],viss[10000];
int c1[15],c[15][10010],n,m,k,tu,tv,tc;
int qu[10010],cntq,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			dp[i][j]=maxint;
		}
	}
	ans=maxint;
	for(int i=0;i<=n;i++){
		for(int j=0;j<200;j++){
			a[i][j].c=maxint;
		}
	}
	for(int i=0;i<m;i++){
		cin>>tu>>tv>>tc;
		add_edge(tu,tv,tc);
	}
	for(int i=1;i<=k;i++){
		cin>>c1[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		dp[0][i]=c1[i]+dp[0][i-1];
	}
	queue<int> q1;
	q1.push(1);int te,g=-1;vis[1]=1;vis[0]=1;viss[1]=1;viss[0]=1;
	while(!q1.empty()){
		g++;
		te=q1.front();q1.pop();
	//	cout<<"Its "<<te<<" now"<<endl;
		for(int i=1;i<=cnt[te];i++){
			if(!vis[a[te][i].v])q1.push(a[te][i].v);
		vis[a[te][i].v]=1;
		}qu[++cntq]=te;if(g==0)continue;
		for(int i=1;i<=cntq;i++){
			for(int j=0;j<=k;j++){
		//	cout<<"Now Check "<<te<<"'s Edge when j="<<j<<endl;
				if(viss[a[te][i].v])dp[g][j]=min(dp[g][j],dp[g-1][j]+a[te][i].c);
			//	cout<<a[te][i].c;
				for(int r=1;r<=j;r++){
					dp[g][j]=min(dp[g][j],dp[g-1][j]+c[r+1][te]+c[r+1][qu[i]]);
				}
			}
		}viss[te]=1;
	}
/*	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}*/
	for(int i=0;i<=k;i++){
		ans=min(ans,dp[n-1][i]);
	}
	cout<<ans;
	return 0;
}
