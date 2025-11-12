#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=1e4+91;
int n,m,k,c[91],idx;
ll a[91][N];
vector<PII> e[N];
struct edge{
	int u,v;ll w;
	bool operator < (const edge other)const {
		return w<other.w;
	}
}kruscal[N<<8];
int fa[N],sum[N];
int find(int x){
	if (x==fa[x]) return x;
	sum[fa[x]]+=sum[x];
	sum[x]=0;
	return fa[x]=find(fa[x]);
}
void merge(int a,int b){
	a=find(a),b=find(b);
	fa[a]=b,sum[b]+=sum[a],sum[a]=0;
}
int cnt[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n+k;i++) fa[i]=i;
	for (int i=1;i<=n;i++) sum[i]=1;
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
		kruscal[++idx]={u,v,w};
	}
	for (int i=1;i<=k;i++){
		scanf("%d",c+i);
		for (int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			e[n+i].push_back(make_pair(j,a[i][j]+c[i]));
			e[j].push_back(make_pair(i+n,a[i][j]+c[i]));
			kruscal[++idx]={j,i+n,a[i][j]+c[i]};
		}
	}
	sort(kruscal+1,kruscal+idx);
	ll ans=0;
	for (int i=1;i<idx;i++){
		if (find(kruscal[i].u)!=find(kruscal[i].v)){
			ans+=kruscal[i].w;
			merge(kruscal[i].u,kruscal[i].v);
			if (kruscal[i].v>n) cnt[kruscal[i].v-n]++;
			if (sum[find(kruscal[i].v)]>=n) break;
		}
	}
	for (int i=1;i<=k;i++)
		ans-=1LL*c[i]*(max(cnt[i]-1,0));
	printf("%lld\n",ans);
	return 0;
}
