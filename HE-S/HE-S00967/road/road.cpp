#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int fa[N];
int u[N],v[N],w[N];
struct Edge{
	int x,y,ret;
	bool operator <(const Edge&cmp)const{
		return ret>cmp.ret;
	}
};
priority_queue<Edge>q;
int c[N],f[11][N];
int a[N];
int n,m,k,ans=1e18;
int find(int x){
	if(fa[x]==x)return x;
	int p=find(fa[x]);
	fa[x]=p;
	return p;
}
int di(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int step=1;
	int ans=0;
	while(step<n){
		
		Edge now=q.top();q.pop();
		int x=find(now.x),y=find(now.y);
		if(x==y)continue;
		step++;
		ans+=now.ret;
		fa[x]=y;
	}
	return ans;
}
void dfs(int x){
	if(x==k+1){
		
		while(!q.empty()){
			q.pop();
		}
		int ret=0;
		for(int i=1;i<=m;i++){
			Edge p;p.x=u[i];p.y=v[i];p.ret=w[i];
			q.push(p);
		}
		int pi=0;
		for(int i=1;i<=k;i++){
			if(a[i]){
				pi++;
				ret+=c[i];
				for(int j=1;j<=n;j++){
					Edge p;p.x=n+pi;p.y=j;p.ret=f[i][j];
					q.push(p);
				}
			}
		}
		int an=ret+di(n+pi);
		ans=min(ans,an);
		return ;
	}
	a[x]=1;
	dfs(x+1);
	a[x]=0;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int flag=0,mi=1e18;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		mi=min(mi,c[i]);
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
			if(f[i][j])flag=1;
		}
	}
	if(flag==0 and k!=0){
		for(int i=1;i<=m;i++){
			Edge p;p.x=u[i];p.y=v[i];p.ret=w[i];
			q.push(p);
		}
		cout<<min(di(n),mi);
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
