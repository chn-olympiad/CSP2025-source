#include<bits/stdc++.h>
#define FILENAME "road"
using namespace std;
const int N=1e4+10,M=1e6+10;

int read(){
	int x=0,k=1;char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*k;
}

//struct Node{
//	int to,w;
//};
//vector<Node> merix[N];
int head[N],nex[M],to[M],dis[M],cnt=0;

void add(int u,int v,int w){
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	dis[cnt]=w;
}

int c[15],a[15][N];

int fa[N],siz[N];
int find(int x){
	return (fa[x]==x)?x:fa[x]=find(x);
}

void unionset(int x,int y){
	x=find(x),y=find(y);
	if(siz[x]<siz[y]) swap(x,y);
	fa[y]=x;
	siz[x]+=siz[y];
	
	
	
}

int main(){
	freopen(FILENAME".in","r",stdin);
	freopen(FILENAME".out","w",stdout);
	int n=read(),m=read(),k=read();
	int ans=0;
	
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	//subtask 1 mintree kru
	if(k==0){
		int r=1,to=0,minn=1e9+10;
		for(int i=1;i<=m;i++){
			int u=read(),v=read(),w=read();
			if(u==v) continue;
			if(u==r){
				if(minn>w) minn=w,to=v;
			}
			if(v==r){
				if(minn>w) minn=w,to=u;
			}
			add(u,v,w);add(v,u,w);
		}
		
		
		for(int i=1;i<=n-1;i++){
			unionset(r,to);
			
		}
	}
	
	cout<<0;
	return 0;
} 
