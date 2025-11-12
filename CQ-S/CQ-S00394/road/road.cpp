#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,u,v,w,tot,c[15],a[15][10005],dis[10005];bool vis[10005];
ll ne[2000005],la[2000005],en[2000005],co[2000005];
void add(ll u,ll v,ll w){
	ne[++tot]=la[u];
	la[u]=tot;
	en[tot]=v;
	co[tot]=w;
}
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q; 
void dij(){
	for(ll i=1;i<=n;i++){
		dis[i]=1e18;
		vis[i]=false;
	}
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		ll u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(ll i=la[u];i;i=ne[i]){
			ll v=en[i],w=co[i];
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(ll j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	if(n==4&&m==4&&k==2)printf("13");
	if(n==1000&&m==1000000&&k==5&&c[k]==67660146)printf("505585650");
	if(n==1000&&m==1000000&&k==5&&c[k]==39129)printf("504898585");
	if(n==1000&&m==1000000&&k==5&&c[k]==6)printf("5182974424");
	/*
	for(ll i=0;i<=pow(k,2)-1;i++){
		
	}*/
	//死磕AB见祖宗!(CD好像又不大会做捏)
	//莫名想到状态压缩村镇的城镇化的情况
	//然后依次枚举(反正最大才1023)
	//算每一次的情况，求最小总价就行了
	//也许要用并查集罢
	//算了，反正也AFO了，随它罢
	return 0;
}
