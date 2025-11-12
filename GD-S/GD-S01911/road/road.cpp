#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=1e6+5,maxn=1e4+5,maxk=15;
int n,m,k,ans;
struct qwq{
	int u,v,w,p;
}a[maxm<<1];
int b[maxk][maxn],c[maxk],fa[maxn];
vector<int>g[11];
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	fa[find(x)]=find(y);
}
inline bool cmp(qwq x,qwq y){
	return x.w<y.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	int cnt=m;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			++cnt;
			a[cnt].u=i;
			a[cnt].v=j;
			a[cnt].w=1e9;
			for(int t=1;t<=k;t++){
				if(b[t][i]+b[t][j]<a[cnt].w){
					a[cnt].w=b[t][i]+b[t][j];
					a[cnt].p=t;
				}
			}
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w,p=a[i].p;
		if(find(u)!=find(v)){
			for(int j=0;j<g[p].size();j++){
				merge(g[p][j],u);
			}
			g[p].push_back(u);
			g[p].push_back(v);
			merge(u,v);
			ans+=w;
		}
	}
	cout<<ans;
	return 0;
}
