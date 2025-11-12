#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#define int long long
using namespace std;
const int N = 2e4+40;
int n,m,k,u,v,w,ans,cst[N],kk;
struct eg{
	int v,w;
};
vector<eg> e[N],t[N];
int a[11][N],al[N],vis[N],cnt;
struct node{
	int p,w,f;
	bool operator < (node x)const{
		return x.w<w;
	}
};priority_queue<node> q;
void bfs(){
	q.push((node){1,0,0});
	++cnt;
	while(q.size()){
		node f=q.top();q.pop();
		if(vis[f.p]==cnt)continue;vis[f.p]=cnt;
		if(f.f)t[f.f].push_back((eg){f.p,f.w}),t[f.p].push_back((eg){f.f,f.w});
		ans+=f.w;
		for(eg v:e[f.p]){
			if(vis[v.v]==cnt)continue;
			q.push((node){v.v,v.w,f.p});
		}
	}
}
void find(){
	while(q.size())q.pop();
	q.push((node){1,0,0});
	++cnt;
	int sum=0;
	for(int i=1;i<=k;i++){
		if(al[i]){
			sum+=cst[i];
		}
	}
//	cerr<<cnt<<'\n';
	while(q.size()){
		node f=q.top();q.pop();
		if(vis[f.p]==cnt)continue;vis[f.p]=cnt;
		sum+=f.w;
		if(f.p>n){
			for(int i=1;i<=n;i++){
				if(vis[i]==cnt)continue;
				q.push((node){i,a[f.p-n][i],f.p});
			}
			continue;
		}
		for(eg v:t[f.p]){
			if(vis[v.v]==cnt)continue;
			q.push((node){v.v,v.w,f.p});
		}
		for(int i=1;i<=k;i++){
			if(al[i]){
				if(vis[i+n]==cnt)continue;
				q.push((node){i+n,a[i][f.p],f.p});
			}
		}
	}
	ans=min(ans,sum);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		e[u].push_back((eg){v,w});
		e[v].push_back((eg){u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>cst[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	bfs();
	for(int i=1;i<1<<k;i++){
		for(int j=1;j<=k;j++)al[j]=(i>>(j-1))&1;
		find();
	}
	cout<<ans;
	return 0;
}
