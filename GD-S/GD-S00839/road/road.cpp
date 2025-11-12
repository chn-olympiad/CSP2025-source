#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fa[10020];
int find(int x){
	return fa[x]!=x?fa[x]=find(fa[x]):x;
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy)fa[fx]=fy;
}
struct edge{
	ll u,v,w;
	int nxt;
	bool b,f;
}e[2500020];
int pre[10200];
int cnt;
void add(int u,int v,int w,bool b=false){
	cnt++;
	e[cnt].u=u,e[cnt].v=v,e[cnt].w=w,e[cnt].b=b,e[cnt].f=false;
	e[cnt].nxt=pre[u];
	pre[u]=cnt;
}
int n,m,k;
ll c[11];
ll a[11][10020];
ll d[10200];
bool check(){
	for(int i=2;i<=n;i++){
		if(find(i)!=find(i-1))return false;
	}
	return true;
}
bitset<10200> vis;
ll ans;
void solve1(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		d[i]=INT_MAX;
	}
	d[1]=0;
	vis[1]=1;
	for(int i=pre[1];i!=0;i=e[i].nxt){
		d[e[i].v]=e[i].w;
	}
	//cerr<<"start prim\n";
	while(!check()){
//		for(int i=1;i<=n;i++)cerr<<d[i]<<" ";
//		cerr<<"\n";
		ll num=INT_MAX,index;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if(e[i].b&&e[i].f)continue;
			if(d[i]<num){
				num=d[i];
				index=i;
			}
		}
		//cerr<<num<<" "<<index<<"\n";
		ans+=num;
		merge(1,index);
		d[index]=0;
		vis[index]=1;
		if(e[index].b)e[index].f=true;
		for(int i=pre[index];i!=0;i=e[i].nxt){
			if(e[i].b&&e[i].f)continue;
			ll to=e[i].v,val=e[i].w;
			d[to]=min(d[to],val);
		}
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		solve1();
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			add(j,n+i,c[i],true);
			add(n+i,j,a[i][j]);
			add(j,n+i,a[i][j]);
		}
	}
//	for(int i=1;i<=cnt;i++){
//		cerr<<i<<":"<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<" "<<e[i].nxt<<"\n";
//	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		d[i]=INT_MAX;
	}
	//cerr<<"init success\n";
	d[1]=0;
	vis[1]=1;
	for(int i=pre[1];i!=0;i=e[i].nxt){
		d[e[i].v]=e[i].w;
	}
	//cerr<<"start prim\n";
	while(!check()){
//		for(int i=1;i<=n+k;i++)cerr<<d[i]<<" ";
//		cerr<<"\n";
		ll num=INT_MAX,index;
		for(int i=1;i<=n+k;i++){
			if(vis[i])continue;
			if(e[i].b&&e[i].f)continue;
			if(d[i]<num){
				num=d[i];
				index=i;
			}
		}
		//cerr<<num<<" "<<index<<"\n";
		ans+=num;
		merge(1,index);
		d[index]=0;
		vis[index]=1;
		if(e[index].b)e[index].f=true;
		for(int i=pre[index];i!=0;i=e[i].nxt){
			if(e[i].b&&e[i].f)continue;
			ll to=e[i].v,val=e[i].w;
			d[to]=min(d[to],val);
		}
	}
	cout<<ans;
	return 0;
}
//rp ++
