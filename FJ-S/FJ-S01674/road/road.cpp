#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
struct Edge{
	int u,v,w;
	Edge(){}
	Edge(int a,int b,int c):u(a),v(b),w(c){}
	bool operator <(const Edge &a)const{
		return w<a.w;
	}
}e[2000005],e1[200005];
int n,m,k,len,fa[20005],siz[20005],a[25][20005],ans=0x7fffffff;
inline int find(int x){
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
} 
inline void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(siz[x]<siz[y])swap(x,y);
	fa[y]=x;
	siz[x]+=siz[y];
}
inline int kruscal(Edge e[],int len){
	int ans=0;
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	sort(e+1,e+len+1);
	for(int i=1,ct=0;i<=len;i++){
		if(find(e[i].u)!=find(e[i].v)){
			merge(e[i].u,e[i].v);
			ans+=e[i].w;
			ct++;
		} 
	}
	return ans;
}
inline void dfs(int step,int key){
	if(step==k){
		for(int i=1;i<=len;i++)e1[i]=e[i];
		int len1=len,sum=0;
		for(int i=1;i<=k&&key;i++,key>>=1){
			if(key&1){
				for(int j=1;j<=n;j++)e1[++len1]=Edge(i+n,j,a[i][j]);
				sum+=a[i][0];
			}
		}
		ans=min(ans,kruscal(e1,len1)+sum);
		return;
	}
	dfs(step+1,key<<1);
	dfs(step+1,key<<1|1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;len=m;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)cin>>a[i][j];
	}
	dfs(0,0);
	cout<<ans;
}
