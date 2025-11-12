#include <bits/stdc++.h>
#define int long long
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
const int INF=0x7fffffff;
const int M=3e6+10;
const int N=1e4+100;
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*f;
}
struct node{
	int v,w;
	int nx;
}e[M];
int ls[N],cnt;
void addEdge(int u,int v,int w){
	e[++cnt]={v,w,ls[u]};
	ls[u]=cnt;
}
int n,m,k,ans,vis[N];
int u,v,w;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		addEdge(u,v,w);
		addEdge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		w=read();
		for(int j=1;j<=n;j++){
			w=read();
			addEdge(n+i,j,w);
			addEdge(j,n+i,w);
		}
	}
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push(mp(0,1));
	while(!q.empty()){
		u=q.top().second;
		w=q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		ans+=w;
		for(int i=ls[u];i;i=e[i].nx){
			v=e[i].v;
			w=e[i].w;
			if(!vis[v]){
				q.push(mp(w,v));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

