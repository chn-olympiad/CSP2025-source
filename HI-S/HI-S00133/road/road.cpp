#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e6+10;
const int N=1e4+10;
const int mod=10000;
struct E{
	int ne,v;
	long long w;
}e[M];
int tot=0,head[N];
bool vis[N];
long long ans=0;
int c[N],cnt=0,n,m,k;
void add(int u,int v,long long w){
	e[++tot].ne=head[u];
	head[u]=tot;
	e[tot].v=v;
	e[tot].w=w;
	e[++tot].ne=head[v];
	head[v]=tot;
	e[tot].v=u;
	e[tot].w=w;
}
priority_queue<long long> q;
void find(){
	q.push(-1);
	while(cnt<n){
		long long num=-q.top();
		q.pop();
		int u=num%mod;
		while(vis[u]){
			num=-q.top();
			u=num%mod;
		}
		long long w=num/mod;
		if(u<=n) cnt++;
		vis[u]=1;
		//cout<<cnt<<": "<<u<<" "<<w<<endl;
		ans+=w;
		for(int i=head[u];i;i=e[i].ne){
			if(vis[e[i].v]) continue;
			if(e[i].v>n){
				q.push(-((e[i].w+c[e[i].v-n])*mod+e[i].v));
			}
			else q.push(-(e[i].w*mod+e[i].v));
		}
	}
	return;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	if(k!=0){
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				int w;
				cin>>w;
				add(n+i,j,w);
			}
		}
	}
	find();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

