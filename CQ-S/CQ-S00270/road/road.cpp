#include <bits/stdc++.h>
using namespace std;
const long long MAXN=1e4+5,MAXM=1<<11,tl=0xc0c0c0c0c0c0c0c0;
long long n,m,k,dp[MAXN][MAXM],c[15],a[15][MAXN],ts[MAXN][MAXM],b[15],lk,mint[MAXN][15];
long long ans;
struct l{
	long long u,v,w;
}dis[MAXN*100];
struct lin{
	long long v,w;
};
struct bcj{
	long long fa,siz;
}tag[MAXN];
vector<lin>lb[MAXN];
bool cmp(l a,l b){
	return a.w<b.w;
}
void mes(){
	for(long long i=1;i<=n;i++){
		tag[i].fa=i;
		tag[i].siz=1;
	}
}
long long find(long long now){
	if(tag[now].fa==now){
		return now;
	}
	return tag[now].fa=find(tag[now].fa);
}
void merge(long long a,long long b){
	a=find(a);
	b=find(b);
	if(a==b){
		return ;
	}
	if(tag[a].siz<tag[b].siz){
		tag[a].fa=b;
		tag[b].siz+=tag[a].siz;
	}
	else{
		tag[b].fa=a;
		tag[a].siz+=tag[b].siz;
	}
}
void dfs(long long now,long long fa,long long alow);
void cal(long long now,long long fa,long long lev,long long tnow,long long spd){
	if(lev==k){
		if(dp[now][tnow]!=tl){
			return ;
		}
		dp[now][tnow]=spd;
		for(long long i=0;i<lb[now].size();i++){
			long long v=lb[now][i].v,w=lb[now][i].w;
			if(v==fa){
				continue;
			}
			dfs(v,now,tnow);
			for(long long j=0;j<k;j++){
				mint[now][j]=min(mint[now][j],mint[v][j]);
			}
			long long str=1e18+7;
			for(long long j=0;j<k;j++){
				if((tnow>>j)&1){
					str=min(str,mint[v][j]);
				}
			}
			dp[now][tnow]+=min(dp[v][tnow]+w,dp[v][0]+str);
		}
		return ;
	}
	cal(now,fa,lev+1,tnow,spd);
	if(!((tnow>>lev)&1)){
		cal(now,fa,lev+1,tnow|b[lev],spd+a[lev+1][now]);
	}
}
void dfs(long long now,long long fa,long long alow){
	for(int j=0;j<k;j++){
		mint[now][j]=min(mint[now][j],a[j+1][now]);
	}
	if(lb[now].size()==1&&lb[now][0].v==fa){
		dp[now][alow]=0;
		return ;
	}
	cal(now,fa,0,alow,0);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	memset(dp,0xc0,sizeof(dp));
	memset(mint,0x3f,sizeof(mint));
	lk=(1<<k);
	b[0]=1;
	for(long long i=1;i<=k;i++){
		b[i]=b[i-1]*2;
	}
	mes();
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		dis[i]={u,v,w};
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(dis+1,dis+m+1,cmp);
	for(long long i=1;i<=m;i++){
		long long u=dis[i].u,v=dis[i].v,w=dis[i].w;
		if(find(u)!=find(v)){
			merge(u,v);
			ans+=w;
			lb[u].push_back({v,w});
			lb[v].push_back({u,w});
		}
	}
	dfs(1,0,0);
	for(long long i=0;i<b[k];i++){
		long long num=0;
		for(long long j=0;j<k;j++){
			if((i>>j)&1){
				num+=c[j+1];
			}
		}
		ans=min(ans,num+dp[1][i]);
	}
	cout<<ans;
	return 0;
}
/*
感觉思路错了。3h没做出来。寄。

UID:894358 binomial 

服了能不能进NOIP都是问题 
*/
