#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e4+15;
const int MAXK=10+5;

int n,m,k;
struct Edge{int u,v,w;};
int c[MAXK],a[MAXK][MAXN];
int f[MAXN];
bool vis[MAXK];
vector<Edge> e;

char gc(){return getchar();}
void pc(char c){putchar(c);}
void read(int &x){
	char c; bool f=false;
	for(;!isdigit(c=getchar());)
		if(c=='-') f=true;
	for(x=c-'0';isdigit(c=getchar());)
		x=x*10+c-'0';
	if(f) x=-x;
}
void write(long long x){
	if(x==0){pc('0');return;}
	if(x<0){pc('-');x=-x;}
	char s[20]; int k=0;
	for(;x;x/=10) s[k++]=x%10+'0';
	for(;k--;) pc(s[k]);
}

void input(){
	read(n),read(m),read(k);
	for(int i=1,u,v,w;i<=m;++i){
		read(u),read(v),read(w);
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;++i){
		read(c[i]);
		for(int j=1;j<=n;++j) read(a[i][j]);
	}
}

int find(int u){return f[u]==u?u:f[u]=find(f[u]);}

void baoli(){//16pts
	sort(e.begin(),e.end(),[](Edge a,Edge b){
		return a.w<b.w;
	});
	for(int i=1;i<=n;++i) f[i]=i;
	long long ans=0;
	int num=0;
	for(Edge i:e){
		int u=i.u,v=i.v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			f[fv]=fu;
			ans+=i.w;
			if(++num==n-1) break;
		}
	}
	write(ans);
}

long long kruskal(){
	vector<Edge> ve=e;
	long long res=0;
	int num=0,x=0;
	for(int i=1;i<=k;++i){
		if(!vis[i]) continue;
		++x;
		for(int j=1;j<=n;++j) ve.push_back({i+n,j,a[i][j]});
	}
	sort(ve.begin(),ve.end(),[](Edge a,Edge b){
		return a.w<b.w;
	});
	for(int i=1;i<=n+k;++i) f[i]=i;
	for(Edge i:ve){
		int u=i.u,v=i.v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			f[fv]=fu;
			res+=i.w;
			if(++num==n+x-1) break;
		}
	}
	for(int i=1;i<=k;++i){
		if(vis[i]) res+=c[i];
	}
	return res;
}

void dfs(int i,long long &ans){
	if(i==k+1){
		ans=min(ans,kruskal());
		return;
	}
	vis[i]=true;
	dfs(i+1,ans);
	vis[i]=false;
	dfs(i+1,ans);
}

void baoli2(){//48pts
	long long ans=1e15;
	dfs(1,ans);
	write(ans);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	input();
	if(k==0) baoli();
	else baoli2();
	return 0;
}

