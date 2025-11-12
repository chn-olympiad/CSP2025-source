#include <bits/stdc++.h>
#define sec second
#define fis first
using namespace std;
struct edge{
	int v,nxt;
	long long w;
}e[2222222];
int cnt,n,nown,m,kkk,uu[1111111],vv[1111111],head[11111],d[11111],fa[11111];
long long ans=0x3f3f3f3f3f3f3f3f,ww[1111111],c[11],a[11][11111],mark[11111];
priority_queue<pair<int,int>>q;
int ff(int now){
	return fa[now]==now?now:fa[now]=ff(fa[now]);
}
void add(int u,int v,long long w){
	++cnt;
	e[cnt].v=v,e[cnt].nxt=head[u],e[cnt].w=w;
	head[u]=cnt;
	q.push({-w,cnt});
	return;
}
long long kruskal(){
	for(int i=1;i<=n+kkk;i++){
		fa[i]=i;
		d[i]=0;
	}
	long long ans=0;
	--nown;
	while(nown){
		int now=q.top().sec,u=e[now^1].v,v=e[now].v;
		q.pop();
		if(ff(u)==ff(v)){
			continue;
		}
		++d[u],++d[v];
		fa[ff(v)]=ff(u);
		ans+=e[now].w;
		mark[v]=mark[u]=e[now].w;
//		cout<<nown<<':'<<u<<"->"<<v<<','<<e[now].w<<'\n';
//		for(int i=1;i<=n+kkk;i++){
//			cout<<ff(i)<<' ';
//		}cout<<'\n';
		--nown;
	}
	for(int i=n+1;i<=n+kkk;i++){
		if(d[i]==1){
			ans-=mark[i];
		}
	}
	return ans;
}
void solve1(){
	for(int i=1;i<=m;i++){
		cin>>uu[i]>>vv[i]>>ww[i];
	}
	for(int i=1;i<=kkk;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int now=0;now<(1<<kkk);now++){
		long long ansnow=0;
		nown=n,cnt=1;
		while(q.size()){
			q.pop();
		}
		for(int i=1;i<=cnt;i++){
			e[i].v=e[i].nxt=e[i].w=0;
		}
		for(int i=1;i<=n;i++){
			head[i]==0;
		}
		for(int i=1;i<=m;i++){
			add(uu[i],vv[i],ww[i]);
			add(vv[i],uu[i],ww[i]);
		}
		for(int i=1;i<=kkk;i++){
			int u=n+i;
			if(now&(1<<i-1)){
				ansnow+=c[i];
				++nown;
				for(int j=1;j<=n;j++){
					add(u,j,a[i][j]);
					add(j,u,a[i][j]);
				}
			}
		}
		ansnow+=kruskal();
//		cout<<ansnow<<'\n';
		ans=min(ans,ansnow);
	}
	cout<<ans;
	return;
}
void solve2(){
	for(int i=1;i<=m;i++){
		cin>>uu[i]>>vv[i]>>ww[i];
	}
	for(int i=1;i<=kkk;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int now=(1<<kkk)-1;
	long long ansnow=0;
	nown=n,cnt=1;
	while(q.size()){
		q.pop();
	}
	for(int i=1;i<=cnt;i++){
		e[i].v=e[i].nxt=e[i].w=0;
	}
	for(int i=1;i<=n;i++){
		head[i]==0;
	}
	for(int i=1;i<=m;i++){
		add(uu[i],vv[i],ww[i]);
		add(vv[i],uu[i],ww[i]);
	}
	for(int i=1;i<=kkk;i++){
		int u=n+i;
		if(now&(1<<i-1)){
			ansnow+=c[i];
			++nown;
			for(int j=1;j<=n;j++){
				add(u,j,a[i][j]);
				add(j,u,a[i][j]);
			}
		}
	}
	ansnow+=kruskal();
//	cout<<ansnow<<'\n';
	ans=min(ans,ansnow);
	cout<<ans;
	return;
}
bool ts=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	if(ts){
		freopen("road3.in","r",stdin);
	}
	else{
		freopen("road.in","r",stdin);
	}
	freopen("road.out","w",stdout);
	cin>>n>>m>>kkk;
	if(m<=100000){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}
