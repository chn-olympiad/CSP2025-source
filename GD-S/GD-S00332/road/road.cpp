#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0x3f3f3f3f;
int che[53];
int cf[53];
struct st{
	int v,w;
};
struct ed{
	int x,y,z;
};
vector<st> e[100053];
stack<ed> q;
int d[100053],vis[100053];
void dfs(int x,int p,int cnt){
	if(cnt>=ans)return;
	if(vis[x])return ;
	vis[x]=1;
	if(x<=n)p++;
	if(p==n){
		ans=min(cnt,ans);
		vis[x]=0;
		return;
	}
//	for(int i=0;i<=n;i++)d[i]=0x3f3f3f3f,vis[i]=0;
//	while(!q.empty())q.pop();
//	d[1]=0;
//	q.push({0,1});
//	while(!q.empty()){
//		ed qt=q.top();
//		q.pop();
//		if(vis[qt.y])continue;
//		else 
//		cntp++;
//		for(auto u:e[qt.second]){
//			q.push({qt.first+u.w,u.v});
//		}
////		cout<<"cnt"<<cnt<<"\n";
//	}
	for(auto u:e[x]){
		if(u.v<=n||che[u.v]==1)dfs(u.v,p,cnt+u.w);
	}
	vis[x]=0;
	return ;
}
//int prim(){
//	int cnt=0,cntp=0; 
//	for(int i=0;i<=n;i++)d[i]=0x3f3f3f3f,vis[i]=0;
//	while(!q.empty())q.pop();
//	d[1]=0;
//	q.push({0,1});
//	while(!q.empty()){
//		auto qt=q.top();
//		q.pop();
//		if(vis[qt.second])continue;
//		cout<<"weizhi:"<<qt.first<<" "<<qt.second<<"\n";
//		vis[qt.second]=1;
//		cout<<cnt<<"d:"<<d[qt.second]<<"\n";
//		cnt+=d[qt.second];
//		cout<<cnt<<"\n";
//		cntp++;
//		for(auto u:e[qt.second]){
//			if(d[u.v]>d[qt.second]+u.w){
//				cout<<"u.v:"<<u.v<<" d[u.v]"<<d[qt.second]+u.w;
//				d[u.v]=d[qt.second]+u.w;
//				q.push({-d[u.v],u.v});
//			}
//		}
//		cout<<"cnt"<<cnt<<"\n";
//	}
//	cout<<"             "<<cnt;
//	return cnt;
//}
int anscnt=0x3f3f3f3f;
void dfs(int x,int da){
	if(x>k){
		cout<<"da"<<da<<"\n";
		ans=0x3f3f3f3f;
		dfs(1,0,0);
		anscnt=min(anscnt,(da+ans));
//		cout<<"ans:"<<da+ans<<"\n";
		return ;
	}
	che[n+x]=1;
	dfs(x+1,da+cf[x]);
	che[n+x]=0;
	dfs(x+1,da);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
//		cout<<z<<"\n";
	}
	for(int i=1;i<=k;i++){
		cin>>cf[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			e[n+i].push_back({j,w});
			e[j].push_back({n+i,w});
		}
	}
	dfs(1,0);
	cout<<anscnt;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
3 4 4
2 4 5
*/

