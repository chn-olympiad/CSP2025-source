#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+5;
struct node{int x,y,val;}e[maxn];
int n,m,k,f[maxn],c[maxn],v[15][50000],tot,ans;
bool cmp(node a,node b){return a.val<b.val;}
int find(int x){return (f[x]==x?x:f[x]=find(f[x]));}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&e[i].x,&e[i].y,&e[i].val);
	tot=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) scanf("%lld",&v[i][j]),e[++tot].x=i+n,e[tot].y=j,e[tot].val=v[i][j];
	}
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=n+k;i++) f[i]=i; 
	for(int i=1;i<=tot;i++){
		if(find(e[i].x)!=find(e[i].y)){
			f[find(e[i].x)]=find(e[i].y);
			ans+=e[i].val;
		}
	}
	cout<<ans;
}

