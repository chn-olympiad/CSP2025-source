#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
struct N{
	int x,y;
	ll v,id;
}v[2000010];
bool cmp(N a,N b){
	return a.v<b.v; 
}
ll c[15],w[15][10010],fa[11010],vis[15];
int find(int x){
	return fa[x]=(fa[x]==x?x:find(fa[x]));
}
ll ans=1e18;
int vv[15],vvv[15];
ll solve(int nn){
	sort(v+1,v+1+m,cmp);
	int cnt=0;
	ll aans=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int j=1;j<=m;j++){
		N i=v[j];
		if((i.x<=n||(i.x>n&&vis[i.x-n]))&&(i.y<=n||(i.y>n&&vis[i.y-n]))&&find(i.x)!=find(i.y)){
			fa[find(i.x)]=find(i.y);
			vv[i.id]=1;
			cnt++;
			aans+=i.v;
		}
		if(cnt==nn-1)break;
	}
	return aans;
}
inline ll min(ll a,ll b){
	return a<b?a:b;
}
inline ll max(ll a,ll b){
	return a>b?a:b;
}
ll yl;
void dfs(int x,int p,ll sc){
	if(sc>ans)return ;
	if(x>k){
		memset(vv,0,sizeof(vv));
		ans=min(ans,solve(p)+sc);
		for(int i=1;i<=k;i++){
			if(vis[i]&&!vv[i])vvv[i]=1;
		}
		return ;
	}
	dfs(x+1,p,sc);
	if(vvv[x])return ;
	vis[x]=1;
	dfs(x+1,p+1,sc+c[x]);
	vis[x]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1,x,y,vv;i<=m;i++){
		cin>>x>>y>>vv;
		v[i]={x,y,vv,0};
	}
	ll xm=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>w[i][j];
		xm=max(xm,c[i]);
	}
	if(k==0){
		sort(v+1,v+1+m,cmp);
		int cnt=0;
		ll ans=0;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int j=1;j<=m;j++){
			N i=v[j];
			if(find(i.x)!=find(i.y)){
				fa[find(i.x)]=find(i.y);
				cnt++;
				ans+=i.v;
			}
			if(cnt==n-1)break;
		}
		cout<<ans;
	}
	else{
		for(int j=1;j<=k;j++){
			for(int i=1;i<=n;i++){
				v[++m]={n+j,i,w[j][i],j};
			}
		}
		for(int i=1;i<=k;i++)vis[i]=1;
		yl=solve(n+k);
		for(int i=1;i<=k;i++)vis[i]=0;
		dfs(1,n,0);
		cout<<ans;
	}
	return 0;
}
/*
4 4 2
1 2 5
2 3 6
3 4 7
4 1 8
0 10 2 2 10
2 3 3 3 3
*/
