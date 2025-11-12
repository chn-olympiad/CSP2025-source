#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
};
using ll=long long;
using pii=pair<int,int>;
int n,m,k;
int p[10015];
ll ans=0x3f3f3f3f3f3f3f3f;
vector<pii> g[10015];
vector<node> edge;
int c[15];
bool f[15];
bool cmp(node x,node y){
	return x.w<y.w;
}
void init(){
	for(int i=1;i<=n+k;i++)p[i]=i;
}
int ufind(int x){
	if(p[x]==x)return x;
	return p[x]=ufind(p[x]);
}
void unite(int x,int y){
	int px=ufind(x),py=ufind(y);
	p[px]=y;
}
void kruskal(int s,int num){
	init();
	ll res=0;
	int cnt=0;
	for(auto e:edge){
		int u=e.u,v=e.v,w=e.w;
		if((u>n&&f[u-n]==false)||(v>n&&f[v-n]==false)||ufind(u)==ufind(v))continue;
		res+=w;
		cnt++;
		unite(u,v);
	}
	if(cnt<num+n-1)return;
	ans=min(ans,res+s);
}
int kruskal1(){
	init();
	ll res=0;
	for(auto e:edge){
		int u=e.u,v=e.v,w=e.w;
		if(ufind(u)==ufind(v))continue;
		res+=w;
		unite(u,v);
	}
	return res;
}
void dfs(int i,int s,int num){
	if(i==k+1){
		kruskal(s,num);
		return;
	}
	f[i]=true;
	dfs(i+1,s+c[i],num+1);
	f[i]=false;
	dfs(i+1,s,num);
}
int read(){
	char c;
	int x=0;
	c=getchar();
	while(c!=' '&&c!='\n'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		g[u].push_back({w,u});
		g[v].push_back({w,v});
		edge.push_back({u,v,w});
	}
	bool f=true;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]!=0)f=false;
		for(int j=1;j<=n;j++){
			int w;
			w=read();
			g[i+n].push_back({w,j});
			edge.push_back({i+n,j,w});
		}
	}
	sort(edge.begin(),edge.end(),cmp);
	if(f){
		cout<<kruskal1();
	}else{
		dfs(1,0,0);
		printf("%lld",ans);
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}
