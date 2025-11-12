#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3fll
#define INFy 0x3f3f3f3f
using namespace std;
int to[3000005],nxt[3000005],head[20005],len[3000005],tot,x,y,z,c[15],a[10005][15];
int to2[20005],nxt2[20005],head2[20005],len2[20005],tot2;
int b[15];
int n,m,k;
bool vis[20005],pan=true;
long long ans=INF,temp,temp2;
int dis[20005],ind[200005];
void add(int x,int y,long long z){
	to[++tot]=y;nxt[tot]=head[x];head[x]=tot;len[tot]=z;
}
void add2(int x,int y,long long z){
	to2[++tot2]=y;nxt2[tot2]=head2[x];head2[x]=tot2;len2[tot2]=z;
}
inline void prim(bool pan){
	for(int i=1;i<=n+k;i++)dis[i]=INFy,vis[i]=false;
	dis[1]=0;
	temp=0;
	priority_queue<pair<int,int> > q;
	q.push({0,1});
	while(!q.empty()){
		int x=q.top().second;
		if(vis[x]){
			q.pop();continue;
		}
		temp+=dis[x];q.pop();
		if(pan&&ind[x]){
			add2(x,ind[x],dis[x]);add2(ind[x],x,dis[x]);
		}
		vis[x]=1;
		for(int e=head[x];e;e=nxt[e]){
			int y=to[e];
			if(vis[y])continue;
			if(y>n&&!b[y-n])continue;
			if(dis[y]>len[e]){
				dis[y]=len[e];ind[y]=x;
				q.push({-dis[y],y});
			}
		}
	}
}
inline void dfs(int step){
	if(step==k+1){
		prim(0);ans=min(ans,temp+temp2);
		return;
	}
	b[step]=0;dfs(step+1);
	b[step]=1;temp2+=c[step];dfs(step+1);
	temp2-=c[step];
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		add(x,y,z);add(y,x,z);
	}
	prim(1);
	memset(to,0,sizeof(to));memset(nxt,0,sizeof(nxt));memset(head,0,sizeof(head));tot=0;memset(len,0,sizeof(len));
	for(int i=1;i<=tot2;i++)to[i]=to2[i],head[i]=head2[i],len[i]=len2[i],nxt[i]=nxt2[i];
	tot=tot2;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])pan=false;
		int minn=INFy;
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
			minn=min(a[j][i],minn);
			add(n+i,j,a[j][i]);
			add(j,n+i,a[j][i]);
		}
		if(minn)pan=false;
	}
	prim(0);
	dfs(1);
	cout<<ans;
	return 0;
}
