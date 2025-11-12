#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2;i -= s3)
#define int long long
#define INF 0x7f7f7f7f
using namespace std;
int n,m,dian,ans,id,ned[20],dis[10100],head[10100];
bool v[10100];
struct edge{
	int v,w,col,next;
}e[2200010];
void add(int u,int v,int w,int c){
	e[++id] = edge{v,w,c,head[u]};
	head[u] = id;
}
priority_queue < pair<int,int> > q;
int prim(int c){
	q = priority_queue< pair<int,int> >();
	q.push({0,1});
	memset(v,0,sizeof(v));
	memset(dis,0x7f,sizeof(dis));
	int u,i,res = 0;
	while(q.size()){
		u = q.top().second;
		if(v[u]){
			q.pop();
			continue;
		}
		v[u] = 1;
		res += -q.top().first;
		q.pop();
		for(i = head[u];i;i = e[i].next) if(!e[i].col || ((c >> e[i].col) & 1)) if(e[i].w < dis[e[i].v]){
			dis[e[i].v] = e[i].w;
			q.push({-e[i].w,e[i].v});
		}
	}
	return res;
}
int dfs(int x,int n,int check){
	if(x > dian){
		return prim(check) + n;
	}
	return min(dfs(x + 1,n + ned[x],check << 1 | 1),dfs(x + 1,n,check << 1));
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>dian;
    int i,j,u,v,w;
    rep(i,1,m,1){
		cin>>u>>v>>w;
		add(u,v,w,0);
		add(v,u,w,0);
	}
	if(m >= 100000){
		ans = prim(0);
		rep(i,1,dian,1){
			cin>>ned[i];
			rep(j,1,n,1){
				cin>>w;
				add(n + i,j,w,i);
				add(j,n + i,w,i);
			}
			ans = min(ans,prim(i << 1) + ned[i]);
		}
		cout<<ans;
	}else{
		rep(i,1,dian,1){
			cin>>ned[i];
			rep(j,1,n,1){
				cin>>w;
				add(n + i,j,w,i);
				add(j,n + i,w,i);
			}
		}
		cout<<dfs(1,0,0);
	}
    return 0;
}
