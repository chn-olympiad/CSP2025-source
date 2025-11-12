#include<bits/stdc++.h>
using namespace std;
struct nd{
	int x,y,w;
};
bool operator < (const nd &a,const nd &b){
	return a.w>b.w;
};
priority_queue<nd> q,q1;
int n,m,u,v,w,fa[1000005],k,ts1;
int xz[15][100005];
nd sc[100005];
int cntt;
long long anss;
int fd(int x){
	if(fa[x]==x)return x;
	return fd(fa[x]); 
}void hb(int x,int y){
	fa[fd(x)]=fd(y);
}bool sm(int x,int y){
	return fd(x)==fd(y);
}void ks(){
	for(int i=1;i<=n;i++)fa[i]=i;
	while(!q.empty()){
		if(!sm(q.top().x,q.top().y)){
			anss+=q.top().w;
			hb(q.top().x,q.top().y);
			cntt++;
			sc[cntt]={q.top().x,q.top().y,q.top().w};
		}q.pop();
	}
}bool vis[15];
long long anss2=1000000000;
void dfs(int now,int ct){
	if(now>k){
		q=q1;
		cntt=anss=0;
		for(int i=1;i<=k;i++){
			if(vis[i]==1){
				for(int j=1;j<=n;j++)q.push({j,n+i,xz[i][j]});
			}
		}ks();
		anss2=min(anss2,anss+ct);
		return;
	}dfs(now+1,ct);
	vis[now]=1;
	dfs(now+1,ct+xz[now][0]);
	vis[now]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	anss2*=1000;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d",&u);
		scanf("%d",&v);
		scanf("%d",&w);
		q.push({u,v,w});
	}for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)scanf("%d",&xz[i][j]);
		if(xz[i][0]!=0)ts1=1;
	}if(k==0){
		ks();
		cout<<anss;
		return 0;
	}if(ts1==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++)q.push({n+i,j,xz[i][j]});
		}n+=k;
		for(int i=1;i<=n;i++)fa[i]=i;
		ks();
		cout<<anss;
		return 0;
	}q1=q;
	dfs(1,0);
	cout<<anss2;
	return 0;
} 
