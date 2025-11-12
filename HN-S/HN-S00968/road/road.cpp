#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+50;
const int maxm=1e6+10;
bool G[maxn][maxn];
int n,m,N,k,cnt,ans;
int rnt;
struct road{
	int u,v,w;
};
road R[maxn*maxn];
bool cmp(road x,road y){
	if(x.w<y.w)return 1;
	return 0;
}
bool check(){
	for(int i=2;i<=n;i++){
		if(!G[1][i])return 1;
	}
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;N=n+k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		//G[u][v]=1;
		//G[v][u]=1;
		road t;t.u=u;t.v=v;t.w=w;
		R[rnt++]=t;//R.push_back(t);
		t.v=u;t.u=v;
		R[rnt++]=t;//R.push_back(t);
		//rnt+=2;
	}
	for(int i=n+1;i<=N;i++){
		int c;cin>>c;
		for(int j=1;j<=n;j++){
			G[i][j]=G[j][i]=1;
			int u=i,v=j,w;
			cin>>w;
			road t;t.u=u;t.v=v;t.w=w;
			R[rnt++]=t;//R.push_back(t);
			t.v=u;t.u=v;
			R[rnt++]=t;//R.push_back(t);
			//rnt+=2;
		}
	}
	sort(R,R+rnt,cmp);
	for(int i=0;i<rnt&&check()/*cnt<=n-1*/;i++){
		if(G[R[i].u][R[i].v]) continue;
		ans+=R[i].w;
		G[R[i].u][R[i].v]=1;
		//if((R[i].u==1)^(R[i].v==1))cnt++;
		for(int j=1;j<=n;j++){
			if(G[R[i].u][j]) G[R[i].v][j]=G[j][R[i].v]=1;
			if(G[R[i].v][j]) G[R[i].u][j]=G[j][R[i].u]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
