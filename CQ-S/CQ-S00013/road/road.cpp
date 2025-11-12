#include <bits/stdc++.h>
using namespace std;
const int N=1e4+20;
int n,idx,m,k;
long long minn=1e15;
int g[N][N],vis[N],g2[N][N],c[N];
struct node{
	int u,v,w;
};
bool operator < (const node &s1,const node &s2){
	return s1.w>s2.w;
}
long long f(){
	memset(vis,0,sizeof(vis));
	priority_queue<node> e;
	for(int i=2;i<=idx;i++){
		if(g[1][i]!=0x3f3f3f3f) e.push({1,i,g[1][i]});
	}
	int cnt=1;
	vis[1]=1;
	long long ans=0,ans2=0x3f3f3f3f3f3f3f3f;
	while(!e.empty() && cnt<n){
		node p=e.top();
		e.pop();
		if(vis[p.v]) continue;
//		cout<<p.u<<" "<<p.v<<" "<<p.w<<"   ";
		vis[p.v]=1;
		if(p.v<=n) cnt++;
		ans+=p.w;
		for(int i=1;i<=idx;i++){
			if(g[p.v][i]!=0x3f3f3f3f && !vis[i]){
				e.push({p.v,i,g[p.v][i]});
			}
		}
	}
//	cout<<endl;
	if(cnt<n){
		return ans2;
	}
	return ans;
}
void dfs(int x,long long sum){
	if(x>k){
		long long x1=f()+sum;
		minn=min(minn,x1);
//		cout<<idx<<" "<<x1<<" "<<sum<<endl;
		return ;
	}
	dfs(x+1,sum);
	idx++;
	for(int i=1;i<=n;i++){
		g[idx][i]=g2[x][i];
		g[i][idx]=g2[x][i];
	}
	dfs(x+1,sum+c[x]);
	idx--;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x1,x2,x3;
		cin>>x1>>x2>>x3;
		g[x1][x2]=x3;
		g[x2][x1]=x3;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>g2[i][j];
		}
	}
	idx=n;
	dfs(1,0);
	cout<<minn;
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

4 2 3
1 2 2
3 4 1
100 100 5 4 100
100 100 100 100 100
10 100 100 100 100

*/
