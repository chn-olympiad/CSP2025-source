#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,cnt,road[10005][10005],c[15][10005],ans,v[15],maxn,fa[10005];
struct dd{
	ll x,y,w;
}dis[10005];
ll fi(ll x){
	if(fa[x]==x)return x;
	return fa[x]=fi(fa[x]);
}
bool cmp(dd x,dd y){
	return x.w<y.y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(dis,1e9+1,sizeof(dis));//初始化 
	for(ll i=1;i<=m;i++){//m条路 
		ll x,y,w;
		cin>>x>>y>>w;
		if(road[x][y]==0){//不存在边，则直接加入 
			dis[++cnt].w=w;//边的值 
			dis[cnt].x=x;
			dis[cnt].y=y;
			road[x][y]=road[y][x]=cnt;//x、y间的边的序号 
		}
		else dis[road[x][y]].w=min(dis[road[x][y]].w,w);//如已存在该边，则替换更小的 
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i][0];//改造费用 
		for(ll j=1;j<=n;j++){
			cin>>c[i][j];//与每个城市修路的费用
		}
	}
	for(ll kk=1;kk<=k;kk++){
		for(ll i=1;i<n;i++)
	        for(ll j=i+1;j<=n;j++)
	        	if(dis[road[i][j]].w>c[kk][i]+c[kk][j])//若修路费用小于原费用，记录贡献值 
	        	    v[kk]=v[kk]+dis[road[i][j]].w-c[kk][i]-c[kk][j];
	    v[kk]-=c[kk][0];//减去改造价钱 
	}
	for(ll i=1;i<=k;i++)
	    maxn=max(maxn,v[i]);//取最大贡献值 
	sort(dis+1,dis+1+cnt,cmp);
	for(ll i=1;i<=cnt;i++)//初始最小费用 
	    if(fi(dis[i].x)!=fi(dis[i].y))ans+=dis[i].w;
	cout<<ans-maxn;//输出最终最小费用 
	return 0;
}
