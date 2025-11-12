#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
int n,m,k; 
const int S=1e3+10,N=1e4+10,M=1e6+10,K=12;
struct node{
	int u,v,w;
}s[M];
int tot;
bool cmp(node A,node B){
	return A.w<B.w;
}
int fa[N];
void Init(){
	for(int i=1;i<=n;i++) fa[i]=i;
} 
int Find(int x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y){
	x=Find(x);
	y=Find(y);
	if(x!=y) fa[x]=y; 
}

int g[S][S],c[K];
int a[K][S],e[S][S];
int solve(int m){
	Init();
	int ret=0,cnt=0;
	for(int i=1;i<=m;i++){
		int u=s[i].u,v=s[i].v,w=s[i].w;
		if(Find(u)!=Find(v)){
			Union(u,v);
			cnt++;
			ret+=w;
		}
		if(cnt==n-1) break;
	}
	return ret;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1,u,v,w;i<=m;i++){
			cin>>u>>v>>w;
			s[++tot]={u,v,w};
		}
		sort(s+1,s+tot+1,cmp);
		cout<<solve(tot);
	}
	else if(n<=1000&&k<=5){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) g[i][j]=4e18;
		}
		for(int i=1,u,v,w;i<=m;i++){
			cin>>u>>v>>w;
			g[u][v]=g[v][u]=w;
		} 
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++) cin>>a[i][j];
		}
		int ans=4e18;
		for(int i=0;i<(1ll<<k);i++){
			int sum=0;
			for(int p=1;p<=n;p++){
				for(int q=1;q<=n;q++) e[p][q]=g[p][q];
			}
			for(int j=1;j<=k;j++){
				if((i>>(j-1))&1){
					sum+=c[j];
					for(int p=1;p<=n;p++){
						for(int q=1;q<=n;q++){
							if(p!=q) e[p][q]=min(e[p][q],a[j][p]+a[j][q]);
						}
					}
				}
			}
			tot=0;
			for(int p=1;p<=n;p++){
				for(int q=1;q<=n;q++){
					s[++tot]={p,q,e[p][q]};
				}
			}
			sort(s+1,s+tot+1,cmp);
			ans=min(ans,sum+solve(tot));
		}
		cout<<ans;
	}
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
