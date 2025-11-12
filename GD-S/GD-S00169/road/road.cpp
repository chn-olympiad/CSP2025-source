#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e7;
long long n,m,k;
long long head[M],nxt[M],to[M],cost[M],cnt;
long long vi[15][N];
void build(int u,int v,int w){
	cnt++;
	nxt[cnt]=head[u];
	to[cnt]=v;
	cost[cnt]=w;
	head[u]=cnt;
	return ;
}
long long dfs(int num){
	long long is[N],anss=0,js=1,now;
	memset(is,0,sizeof(is));
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	is[1]=1;
	for(int i=head[1];i;i=nxt[i]){
		q.push(make_pair(cost[i],to[i]));
	}
	while(!q.empty()&&js<num){
		now=q.top().second;
		while(is[now]){
			q.pop();
			now=q.top().second;
		}
		js++;
		is[now]=1;
		anss+=q.top().first;
		q.pop();
		for(int i=head[now];i;i=nxt[i]){
			q.push(make_pair(cost[i],to[i]));
		}
	}
	return anss;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		build(u,v,w);
		build(v,u,w);
	}
	int maxn=0;
	for(int i=1;i<=k;++i){
		scanf("%d",&vi[i][0]);
//		maxn=max(maxn,vi[i][0]);
		if(vi[i][0]>maxn) maxn=vi[i][0];
		for(int j=1;j<=n;j++){
			scanf("%d",&vi[i][j]);
		}
	}
//	cout<<dfs(n)<<endl;
	if(maxn==0){
//		cout<<" YES!!!"<<endl;
		for(int i=1;i<=k;++i){
			int name=n+i;
			for(int j=1;j<=n;j++){
				build(name,j,vi[i][j]);
				build(j,name,vi[i][j]);
			}
		}
		long long sj=dfs(n);
		printf("%lld",&sj);
		return 0;
	}
	long long ans=dfs(n);
	int record=cnt;
	for(int i=1;i<=k;++i){
		int name=n+i;
		for(int j=1;j<=n;j++){
			build(name,j,vi[i][j]);
			build(j,name,vi[i][j]);
		}
		int js=dfs(n+1)+vi[i][0];
		if(ans>=js){
			n++;
			ans=js;
			record=cnt;
		}
		else{
			for(int i=1;i<=n;++i)	head[i]=nxt[head[i]];
			cnt=record;
			head[name]=0;
		}
	}
	printf("%d",ans);
	return 0;
}
