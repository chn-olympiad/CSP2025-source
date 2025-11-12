#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=1e4+15,M=3e6+5;
int n,m,k,c[15],a[15][N],head[N],tot;
ll ans[1050],len=0x3f3f3f3f3f3f3f3f;
bitset<N>vis[1050];
priority_queue<pii,vector<pii>,greater<pii> >q;
struct node{
	int ver,ne,val;
}g[M];
void read(int &x){
	x=0;char ch=getchar();bool flag=0;
	while(ch<'0'||ch>'9'){if(ch=='-')flag=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(flag)x=-x;
}
void add(int u,int v,int w){
	g[++tot].ver=v;
	g[tot].val=w;
	g[tot].ne=head[u];
	head[u]=tot;
}
void kruscal(int kk){
	q=priority_queue<pii,vector<pii>,greater<pii> >();
	for(int i=head[1];i;i=g[i].ne){
		int y=g[i].ver;
		q.push(make_pair(g[i].val,y));
	}
	while(!q.empty()){
		if(vis[kk]._Find_next(1)>n)return;
		pii xx=q.top();q.pop();
		int dis=xx.first,y=xx.second;
		if(!vis[kk][y])continue;
		if(y>n&&!(kk&(1<<y-n-1)))continue;
		if(y>n)ans[kk]+=c[y-n];
		vis[kk][y]=0;ans[kk]+=dis;
		for(int i=head[y];i;i=g[i].ne){
			int y=g[i].ver;
			if(!vis[kk][y])continue;
			q.push(make_pair(g[i].val,y));
		}
	}
}
int main(){
	freopen("road3.in","r",stdin);
//	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		read(u);read(v);read(w);
		add(u,v,w);add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			read(a[i][j]);
			add(n+i,j,a[i][j]);add(j,n+i,a[i][j]);
		}
	}
//	memset(dis,0x3f,sizeof(dis));
//	dis[1]=0;
	for(int i=0;i<max(1,(1<<k));i++){
		vis[i].set();vis[i][1]=0;
		kruscal(i);
	}
	for(int i=0;i<max(1,(1<<k));i++)len=min(len,ans[i]);
	printf("%lld",len);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
