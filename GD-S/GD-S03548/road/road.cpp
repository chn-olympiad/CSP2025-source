#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
typedef long long ll;
inline int read(){
	int res=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch))
		flag=(ch=='-')?-1:1,
		ch=getchar();
	while(isdigit(ch))
		res=(res<<3)+(res<<1)+(ch^48),
		ch=getchar();
	return res*flag;
}
struct Edge{
	int u,v,w;
	friend bool operator<(Edge x,Edge y){
		return x.w<y.w;
	}
}edge[M<<1];
int n,m,k,ecnt;
int f[N];
int a[15][N]; 
ll ans;
int find(int s){
	return f[s]==s?s:f[s]=find(f[s]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int u,v,w,i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		edge[++ecnt]={u,v,w};
	}
	for(int ciallo,i=1;i<=k;i++){
		ciallo=read();
		for(int j=1;j<=n;j++) edge[++ecnt]={n+i,j,read()};
	}
	for(int i=1;i<=n+k;i++) f[i]=i;
	sort(edge+1,edge+1+ecnt);
	for(int u,v,w,i=1;i<=ecnt;i++){
		u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if(find(u)==find(v)) continue;
		else ans+=w,f[find(u)]=find(v);
	}
	printf("%lld",ans);
	return 0;
}
/*
4 7 0
1 2 1
2 4 10
1 2 5
3 2 2
1 3 5
2 1 7
2 4 1
*/
