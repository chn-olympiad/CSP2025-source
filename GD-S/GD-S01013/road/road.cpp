#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,M=2e6+10,MAXN=1e8;
struct line{
	int from,to,weight;
	bool operator < (const line &A)const{
		return weight<A.weight;
	}
}edge[N+M],redge[M];
int edge_cnt;
int fa[N];
int findroot(int x){
	return (x==fa[x] ? x : fa[x]=findroot(fa[x]));
}
int n,m,k;
int read(){
	int x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';x=x*10+c-'0',c=getchar());
	return x;
}
using namespace std;
int c[N],res=0,node_cnt;
int grp[11][N];
int ans=INT_MAX;
void krusk(){
	int cnt=0;
	for(int x,y,i=1;i<=edge_cnt;i++){
		if(cnt==node_cnt-1)
			break;
		x=findroot(edge[i].to),y=findroot(edge[i].from);
		if(x!=y){
			fa[y]=fa[x];
			res+=edge[i].weight;
			cnt++;
		}
	}
}
void init(int nx){
	edge_cnt=m;
	node_cnt=n;
	res=0;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		edge[i]=redge[i];
	for(int i=1;i<=k;i++){
		if((1<<(i-1))&nx){
			res+=c[i];
			node_cnt++;
			for(int j=1;j<=n;j++){
				edge[++edge_cnt]={i+n,j,grp[i][j]};
			}
		}
	}
	sort(edge+1,edge+1+edge_cnt);
}
int min_ans_edge;
bool taskA=1;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int u,v,w,i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		edge[++edge_cnt]={u,v,w};
		redge[edge_cnt]=edge[edge_cnt];
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		taskA=taskA&(c[i]==0);
		for(int x,j=1;j<=n;j++){
			x=read();
			grp[i][j]=x; 
		}
	}
	for(int state=0;state<(1<<k);state++){
		init(state);
		krusk();
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
/*
3 3 1
1 2 8
2 3 9
1 3 10
0 7 7 7
*/
//k<=5 :(
//rp++
