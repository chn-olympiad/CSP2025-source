#include <bits/stdc++.h>
#define int long long 
#define ld long double
#define ull unsigned long long
#define max3(a,b,c) max(a,max(b,c))
#define fi first
#define se second

using namespace std;
const int N=1010010;
const int M=1e4+15;
//inline int in(){
//	int s=0,w=1;char c=getchar();
//	while(c<'0'||c>'9'){
//		if(c=='-') w=-1;
//		c=getchar();
//	}
//	while(c>='0'&&c<='9'){
//		s=s*10+c-'0'; c=getchar();
//	}return s*w;
//}
struct node{
	int u,v,w;
}g[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int ans=0,n,m,k,sum,tot;
int c[15],fa[M],dis[15];
bool vis[15];
int find(int x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
void dijstl(){
	for(int i=1;i<=M-5;i++) fa[i]=i;
	for(int i=1;i<=tot;i++){
		int u=g[i].u,v=g[i].v,w=g[i].w;
		int fx=find(u),fy=find(v);
		if(fx!=fy){
			fa[fy]=fx;
			if(u>n){
				if(vis[u-n]) ans+=(dis[u-n]+w),sum--,dis[u-n]=0;
				else vis[u-n]=1,dis[u-n]=w;
				//cout<<u<<"     ";
			}
			else if(v>n){
				if(vis[v-n]) ans+=(dis[v-n]+w),sum--,dis[v-n]=0;
				else vis[v-n]=1,dis[v-n]=w;
				//cout<<v<<"     ";
			}
			else{
				ans+=w; sum--;
			}
		}
		//cout<<ans<<' ';
		if(sum==1) break;
	}
	cout<<ans<<"\n";
}
signed main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
		//cout<<i<<' '<<g[i].w<<endl;
	}
	tot=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			++tot; g[tot].u=(i+n);
			g[tot].v=j; g[tot].w=w;
			//cout<<tot<<' '<<g[tot].w<<endl;
		}
	}
	sort(g+1,g+1+tot,cmp);
	sum=n;
	dijstl();
	return 0;
}
