#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e4+25,M=2e6+7;
int n,m,k,eid,p[N],ans,fa[N],cnt;
struct edge{
	int u,v,len,nxt;
	bool operator < (const edge r)const{
		return len<r.len;
	}
}e[M];
void add(int u,int v,int len){
	e[eid].u=u,e[eid].v=v,e[eid].len=len;
	e[eid].nxt=p[u],p[u]=eid++;
}
int get(int x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(p,-1,sizeof p);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,len;
		cin>>u>>v>>len;
		add(u,v,len);
	}
	for(int i=1,c;i<=k;i++){
		cin>>c;
		ans+=c;
		for(int j=1;j<=n;j++){
			int len;
			cin>>len;
			add(i+n,j,len);
		}
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(e,e+m+n*k);
	for(int i=0;i<m+n*k;i++){
		int u=get(e[i].u),v=get(e[i].v);
		if(u!=v){
			fa[u]=v;
			ans+=e[i].len;
			cnt++;
			if(cnt==n+k-1)break;
		}
	}
	cout<<ans;
	return 0;
}
