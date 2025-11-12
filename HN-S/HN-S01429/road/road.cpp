#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N = 1e5+10;
struct node{
	int x,y;
	long long z;
	friend bool operator <(node a,node b){
		return a.z<b.z;
	}
}q[N*10];
struct line{
	int v,w;
}a[15][N];
vector<line> g[N];
int fa[N],c[N],vis[N*10],dep[N],ff[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
map<pair<int,int> ,int>mp;
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x]=f;
	for(int i=0;i<g[x].size();i++){
		int nx =g[x][i].v;
		if(nx!=f){
			dfs(nx,x);
		}
	}
}
bool cmp(line a,line b){
	return a.w<b.w;
}
int read(){
	char c=getchar();
	int k=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k*=10;
		k+=c-'0';
		c=getchar();
	}
	return k*f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		q[i].x=u,q[i].y=v,q[i].z=w;
	}
	sort(q+1,q+1+m);
	int f1=1,f2=1;
	for(int i=1;i<=k;i++){
		ff[i]=1;
		c[i]=read();
		if(c[i])f1=0;
		for(int j=1;j<=n;j++){
			a[i][j].w=read();
			a[i][j].v=j;
			if(a[i][j].w)f2=0;
		}
		sort(a[i]+1,a[i]+1+n,cmp);
	}
	if(f1&&f2){
		cout<<0<<endl;
		return 0;
	}
	long long ans=0;
	int t=0,p;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x= q[i].x,y=q[i].y,z=q[i].z;
		if(find(x)!=find(y)){
			t++;
			ans+=z;
			vis[i]=1;
			fa[find(x)] = find(y);
			g[x].push_back({y,z});
			g[y].push_back({x,z});
		}
		if(t==n-1){
			p = i;
			break;
		}
	}
	if(k==0){
		cout<<ans<<endl;
		return 0;
	}
	dfs(1,1);
	for(int i=p;i>=1;i--){
		if(!vis[i])continue;
		int x= q[i].x,y=q[i].y,z=q[i].z;
		bool fl=0;
		int hu,hv,hh;
		if(dep[x]<dep[y])swap(x,y);
		fa[x]=x;
		int mx =z;
		for(int j=1;j<=k;j++){
			int u=1,v=1;
			while(find(a[j][u].v)!=x){
				u++;
			}
			while(find(a[j][v].v)!=1){
				v++;
			}
			if(c[j]*ff[j]+a[j][u].w+a[j][v].w<mx&&mp[{a[j][u].v,a[j][v].v}]==0){
				fl=1;
				mx=c[j]*ff[j]+a[j][u].w+a[j][v].w;
				hh=j;
				hu=u;
				hv=v;
			}
		}
		if(fl){
			ans-=z;
			ans+=mx;
			ff[hh]=0;
			mp[{a[hh][hu].v,a[hh][hv].v}]=1;
			mp[{a[hh][hv].v,a[hh][hu].v}]=1;
			fa[a[hh][hu].v] = a[hh][hv].v;
			//dfs(a[hh][hu].v,a[hh][hv].v);
		}
	}
	cout<<ans<<endl;
	return 0;
}
