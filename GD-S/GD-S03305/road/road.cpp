#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,fa[N],sz[N];
struct node{
	int u,v,w;
	inline bool operator<(const node &x)const{return w<x.w;}
}a[M],b[M];
inline void init(int n){for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){
	if(sz[x]>sz[y])swap(x,y);
	fa[x]=y,sz[y]+=sz[x];
} 
inline int kruskal(int n,int m){
	init(n+1);
	sort(a+1,a+m+1);
	int tot=0,sum=0;
	for(int i=1;i<=m;i++){
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu!=fv){
			merge(fu,fv);
			b[++tot]=a[i],sum+=a[i].w;
			if(tot==n-1)break;
		}
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	int ans=kruskal(n,m);
	for(int i=1;i<n;i++)a[i]=b[i]; 
	for(int i=1,x;i<=k;i++){
		cin>>x;
		for(int j=1,v;j<=n;j++){
			cin>>v;
			a[n-1+j]={n+i,j,v};
		}
		int res=kruskal(n+1,n*2-1);
		if(res+x<ans){
			ans=res+x;
			for(int j=1;j<n;j++)a[j]=b[j];
			n++;
		}
		else for(int j=1;j<n;j++)b[j]=a[j];
	}
	cout<<ans;
	return 0;
}
