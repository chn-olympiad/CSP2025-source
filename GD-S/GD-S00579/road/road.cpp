#include <bits/stdc++.h>
#define ll long long
#define FRE
using namespace std;
int read(){
	int t1=0,t2=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')t2=-1;
		c=getchar();
	}while(c>='0' && c<='9')t1=t1*10+c-'0',c=getchar();
	return t1*t2;
}
const int N=1000001;
int n,m,k,idx=0,h[N],ans,fa[N],c[11][N],b[N];
bool vis[N];
struct node{
	int u,to,val,next;
}ed[N];
void build(int u,int v,int val){
	ed[++idx].to=v;
	ed[idx].u=u;
	ed[idx].val=val;
	ed[idx].next=h[u];
	h[u]=idx;
}
int getfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
bool cmp(node a,node b){
	return a.val<b.val;
}
int kruskal(){
	int ans=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(ed+1,ed+1+m,cmp);
	for(int i=1;i<=idx;i++){
		int v=ed[i].to,u=ed[i].u;
		if(getfa(v)==getfa(u))continue;
		fa[getfa(u)]=getfa(v);
		ans+=ed[i].val;
	}return ans;
}
int main(){
	#ifdef FRE
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int u,v,val;u=read();v=read();val=read();
		build(u,v,val);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			if(j==1)cin>>b[i];
			else cin>>c[i][j];
		}
	}
	if(k==0){
		cout<<kruskal();
	}
	return 0;
}

