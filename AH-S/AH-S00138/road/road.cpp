#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5,MAXM=1e6+5,MAXK=10+5;
struct L{
	long long b,v;
};
struct LL{
	long long u,v,w;
};
bool cmp(LL a,LL b){
	return a.w<b.w;
}
long long n,m,k,mi=1e16;
long long c[MAXK];
vector<L> tu[MAXN],b[MAXK];
int fa[MAXN];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
long long zx(int x){
	long long sum=0;
	vector<LL> t;
	for(int i=1;i<=n;i++){
		int len=tu[i].size();
		for(int j=0;j<len;j++){
			t.push_back({i,tu[i][j].b,tu[i][j].v});
		}
	}
	bool vis[MAXN+MAXK];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		vis[i]=1;
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		int oo=(1<<(i-1));
		if((oo&x)){
			vis[n+i]=1;
			fa[n+i]=n+i;
			sum+=c[i];
			int len=b[i].size();
			for(int j=0;j<len;j++){
				t.push_back({n+i,b[i][j].b,b[i][j].v});
			}
		}
	}
	sort(t.begin(),t.end(),cmp);
	int len=t.size();
	for(int i=0;i<len;i++){
		if(vis[t[i].u]&&vis[t[i].v]){
			int f1=find(t[i].u),f2=find(t[i].v);
			if(f1!=f2){
				fa[f1]=f2;
				sum+=t[i].w;
			}
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		tu[u].push_back({v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++){
			long long w;
			cin>>w;
			b[i].push_back({j,w});
		}
	}
	for(int i=0;i<(1<<k);i++){
		mi=min(mi,zx(i));
	}
	cout<<mi;
	return 0;
}
