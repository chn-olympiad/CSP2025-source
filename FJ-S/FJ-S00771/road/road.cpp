#include<bits/stdc++.h>
#include<queue>
using namespace std;
const int N=2e4+15,M=3e6+15,INF=0x3f3f3f3f3f3f3f3f;
struct Node {
	int y,z;
	long long val;
	bool operator < (const Node A) const {
		return val>A.val;
	}
}node,bian[M];
int fff,hh;
int fa[N],siz[N],viss[N];
int n,m,k,u,v,len,vis[N],chk[20],jl[N],llen;
int hd_e[M<<1],to_e[M<<1],nxt_e[M<<1],cnte;
long long w,ds_e[M<<1],dis[N],sum,arr[20][N],crr[20],mn=INF;
priority_queue <Node> q;
long long minn (long long a,long long b) {
	if(a>b) {
		return b;
	}
	return a;
}
void add_e (int u,int v,long long w) {
	nxt_e[++cnte]=hd_e[u];
	hd_e[u]=cnte;
	to_e[cnte]=v;
	ds_e[cnte]=w;
}
void prim () {
	while(!q.empty()) {
		q.pop();
	}
	for(int i=1;i<=n+k;i++) {
		dis[i]=INF;
		vis[i]=0;
	}
	sum=0ll;
	dis[1]=0ll;
	node.y=1;
	node.val=0ll;
	q.push(node);
	int cnt=0;
	while(!q.empty()) {
		node=q.top();
		q.pop();
		int x=node.y;
		if(vis[x]) {
			continue;
		}
		vis[x]=1;
		sum+=node.val;
		cnt++;
		if(cnt>=len) {
			break;
		}
		if(x>n) {
			for(int i=1;i<=n;i++) {
				if(dis[i]>arr[x-n][i]&&vis[i]==0) {
					dis[i]=arr[x-n][i];
					node.y=i;
					node.val=arr[x-n][i];
					q.push(node);
				}
			}
		}else {
			for(int i=hd_e[x];i;i=nxt_e[i]) {
				int y=to_e[i];
				long long v=ds_e[i];
				if(dis[y]>v&&vis[y]==0) {
					dis[y]=v;
					node.y=y;
					node.val=v;
					q.push(node);
				}
			}
			for(int i=1;i<=k;i++) {
				//cout<<chk[i]<<" ";
				if(chk[i]==0) {
					continue;
				}
				if(dis[n+i]>arr[i][x]&&vis[n+i]==0) {
					dis[n+i]=arr[i][x];
					node.y=n+i;
					node.val=arr[i][x];
					q.push(node);
				}
			}
		}
		
	}
//	for(int i=1;i<=n+k;i++) {
//		cout<<dis[i]<<" ";
//	}
}
bool cmp (Node a,Node b) {
	return a.val<b.val;
}
int find (int x) {
	if(x==fa[x]) return x;
	return (x=find(fa[x]));
} 
void solv () {
	sort(bian+1,bian+hh+1,cmp);
	for(int i=1;i<=n+k;i++) {
		fa[i]=i;
		siz[i]=1;
	}int g=0;
	for(int i=1;i<=hh;i++) {
		int x=find(bian[i].y);
		int y=find(bian[i].z);
		if(x==y) {
			continue;
		}
		if(siz[x]<siz[y]) swap(x,y);
		fa[y]=x;
		siz[y]=0;
		sum+=bian[i].val;
		if(bian[i].y<=n&&viss[bian[i].y]==0) {
			viss[bian[i].y]=1;
			g++;
		}
		if(bian[i].z<=n&&viss[bian[i].z]==0) {
			viss[bian[i].z]=1;
			g++;
		}
	}
	cout<<sum;
}
int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%lld",&u,&v,&w);
		add_e(u,v,w);
		add_e(v,u,w);
		bian[++hh].y=u;
		bian[hh].z=v;
		bian[hh].val=w;
	}
	for(int i=1;i<=k;i++) {
		scanf("%lld",&crr[i]);
		if(crr[i]>0) {
			fff=1;
		}
		for(int j=1;j<=n;j++) {
			scanf("%lld",&arr[i][j]);
			
			bian[++hh].y=i+n;
			bian[hh].z=j;
			bian[hh].val=arr[i][j];
		}
	}
	if(fff==0) {
		solv();
		return 0;
	}
	for(int i=0;i<(1<<k);i++) {
		len=n;
		sum=0;
		int flg=0;
		for(int j=1;j<=llen;j++) {
			if(jl[j]==(i|jl[j])) {
				flg=1;
				break; 
			}
		}
		if(flg==1) {
			continue;
		}
		for(int j=0;j<k;j++) {
			if((i&(1<<j))>0) {
				chk[j+1]=1;
				len++;
			}
		}
		prim();
		for(int j=0;j<k;j++) {
			chk[j+1]=0;
			if((i&(1<<j))>0) {
				sum+=crr[j+1];
			}
		}
		if(sum<mn) {
			mn=sum;
		}else {
			jl[++llen]=i;
		}
	}
	printf("%lld",mn);
	return 0;
}

