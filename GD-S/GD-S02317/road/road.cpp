#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define tu pair<ll,pair<ll,ll> >
#define F first
#define S second
ll n,m,k,f,c[11],cw[11][10005],fa[10005],ans,cnt;
priority_queue<tu,vector<tu >,greater<tu> > q;
int find_set(int x){
	if(x!=fa[x])return fa[x]=find_set(fa[x]);
	return x;
}
void Klskr(){
	for(int i=1;i<=n;i++)fa[i]=i;
	while(!q.empty()){
		tu t=q.top();
		q.pop();
		int x=t.S.F,y=t.S.S;
		if(find_set(x)==find_set(y))continue;
		fa[y]=x;
		cnt++;
		ans+=t.F;
	}
	return ;
}
void add(int u,int v,int w){
	tu t;
	t.F=w;
	t.S.F=u;
	t.S.S=v;
	q.push(t);
	return ;
}
void addedge(int x){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)add(i,j,cw[x][i]+cw[x][j]);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>cw[i][j];
		if(c[i]==0)addedge(i);
	}
	Klskr();
	cout<<ans;
	return 0;
}
