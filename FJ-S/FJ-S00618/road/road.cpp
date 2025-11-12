#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define lc(p) ((p)*2)
#define rc(p) ((p)*2+1)
#define mkpr make_pair
#define fir first
#define sec second
using namespace std;
const int M=1000006,N=10050;
int n,m,k;
LL c[15];
struct node {
	int u,v;
	LL w;
	int t;
} e[M<<1];
bool cmp(node x,node y) {
	return x.w<y.w;
}
int fa[N];
int find(int x) {
	//cout<<x<<endl;
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int vis[15];
LL ans=1e18;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1,x,y,w; i<=m; i++) {
		cin>>x>>y>>w;
		e[i]= {x,y,w,0};
	}
	for(int i=1; i<=k; ++i) {
		cin>>c[i];
		for(int j=1,x; j<=n; j++) {
			cin>>x;
			e[++m]= {n+i,j,x,i};
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int i=0; i<(1<<k); i++) {
		for(int j=1; j<=n+k; j++) {
			fa[j]=j;
		}
		int tmp=0;
		LL res=0;
		vis[0]=1;
		for(int j=1; j<=k; j++) {
			vis[j]=((i>>(j-1))&1);
			//	cout<<vis[j]<<' ';
			tmp+=vis[j];
			res+=c[j]*vis[j];
		}
		//	cout<<endl;
		int cnt=0;
		for(int j=1; j<=m; j++) {
			//	cout<<"fds:"<<vis[e[j].t]<<endl;
			if(!vis[e[j].t])continue;
			int u=e[j].u;
			int v=e[j].v;
		//	cout<<u<<' '<<v<<' '<<e[j].w<<endl;
			if(find(u)!=find(v)) {
				fa[find(u)]=find(v);
				res+=e[j].w;
				cnt++;
				if(cnt==n+tmp-1)break;
			}
		}
		if(cnt==n+tmp-1) {
		//	cout<<res<<endl;
			ans=min(ans,res);
		}
	}
	cout<<ans;
	return 0;
}
