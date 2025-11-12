#include<bits/stdc++.h>
#define int long long
using namespace std;
using pii=pair<int,int>;
const int N=5e3+11;
int n,m,k,a[N][N],c[N];
int f[N],g[N][N],tg[N][N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void initg(){for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=LLONG_MAX;}
void inittg(){for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)tg[i][j]=LLONG_MAX;}
void gtotg(){for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)tg[i][j]=g[i][j];}
void tgtog(){for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=tg[i][j];}
int solvek(int exl){
	for(int i=0;i<=n;i++)f[i]=i;
	vector<array<int,3>>ed; 
	for(int i=1;i<=n+exl;i++)
		for(int j=i+1;j<=n+exl;j++)
			if(tg[i][j]!=LLONG_MAX)ed.push_back({tg[i][j],i,j});
	sort(ed.begin(),ed.end());
	inittg();
	int ans=0;
	for(auto t:ed)
		if(find(t[1])!=find(t[2])){
			f[find(t[1])]=find(t[2]);
			tg[t[1]][t[2]]=tg[t[2]][t[1]]=t[0];//变为最小生成树 
			ans+=t[0];
		}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	initg();
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	gtotg();
	int ans=solvek(0);
	tgtog();
	if(k==0){
		cout<<ans;
		return 0;
	}
	int exsum=0,exl=1;
	for(int i=1;i<=k;i++){
		gtotg();
		for(int j=1;j<=n;j++)
			tg[j][n+exl]=tg[n+exl][j]=a[i][j];
		int t=solvek(exl)+c[i]+exsum;
		if(t<ans){
			ans=t;
			exl++;
			exsum+=c[i];
			tgtog();
		}
	}
	cout<<ans;
	return 0;
}/*
4 4 2
1 4 6
3 4 4
2 4 5
2 3 7 
1 1 8 2 4
2 9 1 9 1
*/ 
