#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20010,M=1e6+10,K=12;
struct Hutao{
	int u,v,w;
} ht[M];
int a[K][N],c[K];
int f[N],sz[N];
bool cmp(Hutao a,Hutao b){
	return a.w<b.w;
}
int find(int x){
	return f[x]==x ? x : f[x]=find(f[x]);
}
vector<Hutao> frn,ys;
int read(){
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		ht[i].u=read(),ht[i].v=read(),ht[i].w=read();
	}
	sort(ht+1,ht+1+m,cmp);
	bool flag=true;
	for(int i=1;i<=k;i++){
		c[i]=read();
		bool fl=false;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			if(a[i][j]==0) fl=true;
		}
		if(!fl || c[i]!=0) flag=false; 
	}
	if(flag){
		for(int i=1;i<=k;i++){
			int id=0;
			for(int j=1;j<=n;j++) if(a[i][j]==0) id=j;
			for(int j=1;j<=n;j++) if(id!=j) ht[++m].u=id,ht[m].v=j,ht[m].w=a[i][j];
		}
		sort(ht+1,ht+1+m,cmp);
		int ans=0;
		for(int i=1;i<=n;i++) f[i]=i,sz[i]=1;
		for(int i=1;i<=m;i++){
			int u=ht[i].u,v=ht[i].v,w=ht[i].w;
			int a=find(u),b=find(v);
			if(a==b) continue;
			if(sz[a]>sz[b]) swap(a,b);
			f[a]=b;
			sz[b]+=sz[a];
			ans+=w;
		}
		printf("%lld\n",ans);
		return 0;
	}
	int ans=1e18;
	for(int s=0;s<(1<<k);s++){
		if(s*1.5>(1<<8)) break;
		frn.clear(),ys.clear();
		for(int j=0;j<k;j++) if(s>>j&1){
			for(int p=1;p<=n;p++) frn.push_back({n+j+1,p,a[j+1][p]});
		}
		for(int j=1;j<=n+k;j++) f[j]=j,sz[j]=1;
		sort(frn.begin(),frn.end(),cmp);
		int i=1,j=0;
		while(i<=m && j<(int)frn.size()){
			if(ht[i].w<frn[j].w) ys.push_back(ht[i]),i++;
			else ys.push_back(frn[j]),j++;
		}
		while(i<=m) ys.push_back(ht[i]),i++;
		while(j<(int)frn.size()) ys.push_back(frn[j]),j++;
		int sum=0;
		for(int i=0;i<k;i++) if(s>>i&1) sum+=c[i+1];
		for(int i=0;i<(int)ys.size();i++){
			int u=ys[i].u,v=ys[i].v,w=ys[i].w;
			int a=find(u),b=find(v);
			if(a==b) continue;
			if(sz[a]>sz[b]) swap(a,b);
			f[a]=b;
			sz[b]+=sz[a];
			sum+=w;
			if(sum>ans) break;
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}