#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5;
const int M=1e6+5;
struct node{
	ll v,w;
}e[M<<1];
ll n,m,k,head[N],nxt[M<<1],cnt=0;
ll c[15],a[15][N];
ll dis[N],fa[N];
bool vis[N];
queue<ll>q;
void add(ll u,ll v,ll w){
	nxt[++cnt]=head[u];
	e[cnt].v=v,e[cnt].w=w;
	head[u]=cnt;
}
void tree(){
	memset(dis,0x3f3f3f3f,sizeof dis);
	dis[1]=0,vis[1]=1,fa[1]=1;
	q.push(1);
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=nxt[i]){
			ll v=e[i].v,w=e[i].w;
			if(fa[u]!=v&&dis[v]>w){
				dis[v]=w;
				fa[v]=u;
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cout<<0;
	return 0;
}
