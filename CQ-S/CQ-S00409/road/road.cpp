#include<bits/stdc++.h> 
using namespace std;
const int N=10015;
struct node{
	int u,v,w;
}e[1000005];
struct nod{
	int v,w;
};
long long n,m,k,ans=LONG_LONG_MAX,n2,cnt;
int nw[N],na[15][N],c[N],fa[N];
bool mark[N];
vector<nod> a[N];
node mp[1000005];
inline bool cmp(node x,node y){
	return x.w<y.w;
}
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
inline long long bfs(){
	cnt=0;
	n2=n;
	for(int i=1;i<=k;i++){
		if(mark[i]) c[++n2]=i+n;
	}
	for(int i=1;i<=n2;i++){
		for(int j=0;j<a[c[i]].size();j++){
			int v=a[c[i]][j].v,w=a[c[i]][j].w;
			if(c[i]<v){
				if(v<=n||(v>n&&mark[v-n]))
				e[++cnt]={c[i],v,w};
			}
		}
		fa[c[i]]=c[i];
	}
	int i=1,t=0;
	long long sum=0;
	for(int i=1;i<=k;i++){
		if(mark[i]) sum+=nw[i];
	}
	sort(e+1,e+1+cnt,cmp);
	while(i<=cnt&&t+1<n2){
		int u=e[i].u,v=e[i].v,w=e[i].w,fu=find(u),fv=find(v);
		if(fu==fv){
			i++;
			continue;
		}
		sum+=w;
		if(sum>ans) break;
		fa[fu]=fv;
		t++,i++;
	}
	for(int j=1;j<=cnt;j++) e[j].u=e[j].v=e[j].w=0;
	return sum;
}
inline void dfs(int d){
	if(d>k){
		ans=min(ans,bfs());
		return;
	}
	dfs(d+1);
	mark[d]=1;
	dfs(d+1);
	mark[d]=0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt]={min(u,v),max(u,v),w};
	}
	for(int i=1;i<=n;i++) c[i]=i,fa[i]=i;
	int p=1,t=0;
	sort(e+1,e+1+cnt,cmp);
	int cnt2=0;
	while(p<=cnt&&t+1<n){
		int u=e[p].u,v=e[p].v,w=e[p].w,fu=find(u),fv=find(v);
		if(fu==fv){p++;continue;}
		mp[++cnt2]={u,v,w};
		fa[fu]=fv;
		t++;p++;
	}
	for(int i=1;i<=cnt;i++) e[i].u=e[i].v=e[i].w=0;
	for(int i=1;i<=cnt2;i++){
		a[mp[i].u].push_back({mp[i].v,mp[i].w});
	}
	for(int i=1;i<=k;i++){
		cin>>nw[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			a[j].push_back({i+n,w});
		}
	}
	bool flg=0;
	for(int i=1;i<=k;i++){
		if(nw[i]>0) flg=1;
	}
	if(!flg){
		for(int i=1;i<=k;i++) mark[i]=1;
		cout<<bfs();
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
2^k*n*(k+1)*log(n*(k+1))
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

