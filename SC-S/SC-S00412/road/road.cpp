#include<bits/stdc++.h>
#define ll long long 
using namespace std;
inline int read(){
	int x=0,f=1; char c=0;
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x*f;
}
const int N=1e5+10,M=5e6+10;
const ll inf=1e18;
int n,m,k;
int dsu[N];
vector<int> g[N];
inline int find(int x){
	if(dsu[x]==x) return x;
	return dsu[x]=find(dsu[x]);
}
struct node{
	int u,v,w,id;
}edg[M],fir[N];
bool del[N<<1];
int ne[N<<1],e[N<<1],h[N],idx;
inline void add(int a,int b){
	ne[idx]=h[a];e[idx]=b;h[a]=idx++;
}
struct knode{
	ll cost;
	int a[10010];
	int id;
}key[15];
bool st[15][N];
inline bool cmp(node a,node b){
	return a.w<b.w;
}
inline bool cmp2(node a,node b){
	return a.w>b.w;
}
vector<int> vu,vv;
inline void dfs(bool type,int u,int fa){
	if(!type) vu.push_back(u);
	else vv.push_back(u);
	for(int i=h[u];~i;i=ne[i]){
		if(del[i]) continue;
		if(e[i]==fa) continue;
		dfs(type,e[i],u);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(h,-1,sizeof h);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++) dsu[i]=i;
	for(int i=1;i<=m;i++) 
		edg[i]=(node){read(),read(),read(),0};
	for(int i=1;i<=k;i++){
		key[i].cost=read();
		for(int j=1;j<=n;j++) key[i].a[j]=read();
		int mn=key[i].a[1];
		key[i].id=1;
		for(int j=1;j<=n;j++) if(key[i].a[j]<mn){
			mn=key[i].a[j];
			key[i].id=j;
		}
		key[i].cost+=mn;
	}
	sort(edg+1,edg+m+1,cmp);
	int cnt=0;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u=edg[i].u,v=edg[i].v,w=edg[i].w;
		u=find(u),v=find(v);
		if(u!=v){
			cnt++;
			dsu[v]=u;
			fir[cnt]=(node){u,v,w,idx};
			add(u,v);
			add(v,u);
			ans+=w;
			if(cnt>=n-1) break;
		}		
	}
	sort(fir+1,fir+cnt+1,cmp2);
	ll sum=ans;
	for(int S=1;S<=(1<<n)-1;S++){
		ll delta=0;
		for(int i=0;i<=idx;i++) del[i]=false;
		for(int j=1;j<=k;j++)
			if(S&(1<<(j-1))){
				for(int i=1;i<=n;i++) st[j][i]=false;
				st[j][key[j].id]=true;
			}
		for(int i=1;i<=cnt;i++){
			int u=fir[i].u,v=fir[i].v,w=fir[i].w,nid=fir[i].id;
			del[nid]=del[nid^1]=true;
			vu.clear(),vv.clear();
			dfs(0,u,u);
			dfs(1,v,v);
			ll res=inf;
			int sid,Tu,Tv;
			for(int j=1;j<=k;j++){
				if(S&(1<<(j-1))){
					ll tot=0,now=inf;
					int tu;
					for(auto u:vu){
						if(st[j][u]){
							tu=u;
							now=0;
							break;
						}
						if(key[j].a[u]<now) tu=u,now=key[j].a[u];
					}
					tot+=now,now=inf;
					int tv;
					for(auto u:vv){
						if(st[j][u]){
							tv=u;
							now=0;
							break;
						}
						if(key[j].a[u]<now) tv=u,now=key[j].a[u];
					}
					tot+=now;
					if(tot<res){
						res=tot;
						sid=j;
						Tu=tu,Tv=tv;
					}
				}
			}
			if(res>=w) del[nid]=del[nid^1]=false;
			else{
				delta+=w-res;
				st[sid][Tu]=st[sid][Tv]=true;
			}
		}
		delta=-delta;
		for(int j=1;j<=k;j++)
			if(S&(1<<(j-1))) delta+=key[j].cost;
		if(delta<0) ans=min(ans,sum+delta);
	}
	printf("%lld\n",ans);
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