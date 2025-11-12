#include <bits/stdc++.h>
using namespace std;
const int N=1e4+20,M=1e6+10;
typedef long long ll;
int n,m,k,a[15][N],p[N],flushed,sum;
ll ans=0x3f3f3f3f3f3f3f3f;
bool vlg[15]; //village
struct Edge{
	ll u,v,w;
	bool operator < (Edge const &rhs) const{
		return w>rhs.w;
	}
}t,e[M];
inline int find(int x){
	if (x!=p[x]) return p[x]=find(p[x]);
	return p[x];
}
void tree(bitset<10> village){
	memset(vlg,0,sizeof vlg);
	priority_queue<Edge> pq;
	for (int i=1;i<=m;i++) pq.push(e[i]);
	for (int i=1;i<=n;i++) p[i]=i;
	ll q=n,sum=0;
	for (int i=0;i<10;i++){
		if (village[i]){
			++q;
			p[q]=q;
			for (int j=1;j<=n;j++)
				pq.push({q,j,a[i+1][j]+a[i+1][0]});
		}
	}
	while (!pq.empty()){
		t=pq.top(); pq.pop();
		int u=t.u,v=t.v,w=t.w;
		if (u>n && vlg[u-n]){
			pq.push({u,v,w-a[u][0]});
			continue;
		}
		int x=find(u),y=find(v);
		if (x==y) continue;
		p[y]=x;
		if (u>n) vlg[u]=1;
		sum+=w;
	}
	ans=min(ans,sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(); cout.tie();
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for (int i=1;i<=k;i++){
		cin>>a[i][0];
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	bitset<10> bs;
	for (int i=0;i<=k;i++){
		sum+=(bool)i;
		bs=sum;
		tree(bs);
	}
	cout<<ans;
	return 0;
}
