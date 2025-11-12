#include<bits/stdc++.h>
using namespace std;
long long n,m,k,pre[10110],k1,c[20],b[20][10010],d[100010],bj[101010],ans1,pp=0;
struct st{
	int u,v,next,w;
}a[11000010];
queue<int>q;
int dfs(long long x,long long cnt,long long ans){
	if(cnt==n+k){
		ans1=ans;
		return 0;
	}
	for(int i=pre[x];i>0;i=a[i].next){
		if(bj[a[i].v]==1){
			continue;
		}
		bj[a[i].v]=1;
		dfs(a[i].v,cnt+1,ans+max(pp,d[a[i].v]-d[x]));
	}
	return 0;
}
void add(int u,int v,int w){
	k1++;
	a[k1].u=u;
	a[k1].v=v;
	a[k1].w=w;
	a[k1].next=pre[u];
	pre[u]=k1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u1,v1,w1;
		cin>>u1>>v1>>w1;
		add(u1,v1,w1);
		add(v1,u1,w1);
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
			add(n+i,j,b[i][j]);
			add(j,n+i,b[i][j]);
		}
		d[n+i]=c[i];
		q.push(n+i);
	}
	if(q.empty()){
		q.push(n+1);
	}
	while(!q.empty()){
		long long t=q.front();
		q.pop();
		for(int i=pre[t];i>0;i=a[i].next){
			if(d[a[i].v]>d[a[i].u]+a[i].w){
				d[a[i].v]=d[a[i].u]+a[i].w;
				q.push(a[i].v);
			}
		}
	}
	bj[n+1]=1;
	dfs(n+1,1,0);
	cout<<ans1;
	return 0;
}
