#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+5,N=1e4+5;
int n,m,k,tot,fa[N*2],ans,s[N];
struct node {
	int u,v,w,id;
	bool operator <(const node o)const {
		return w<o.w;
	}
}e1[M],e2[M];
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y) {
	int fx=find(x),fy=find(y);
	if(fx==fy) return false;
	fa[fx]=fy;
	return true;
}
void solve(int key) {
	int cnt=0,res=0;
	for(int i=1;i<=k;i++) if((key>>i-1)&1) res+=s[i],cnt--;
//	cout<<key<<" "<<cnt<<"\n";
	for(int i=1;i<=tot;i++) {
		if(cnt==n-1) {
//			cout<<key<<"!"<<res<<"\n";
			ans=min(ans,res);
			return ;
		}
		if(e2[i].id!=0&&((key>>e2[i].id-1)&1)==0) continue;
		if(merge(e2[i].u,e2[i].v)) {
//			cout<<e2[i].u<<" "<<e2[i].v<<"\n";
			cnt++,res+=e2[i].w;
		}
	}
//	cout<<cnt<<"\n";
}
signed main() {
	freopen("road.in","r",stdin);
//	freopen("road3.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e1[i].u>>e1[i].v>>e1[i].w;
	sort(e1+1,e1+1+m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		if(merge(e1[i].u,e1[i].v)) e2[++tot]=e1[i],ans+=e1[i].w;
	}
//	cout<<ans<<"\n";
	for(int i=1;i<=k;i++) {
		cin>>s[i];
		for(int j=1;j<=n;j++) {
			++tot;
			cin>>e2[tot].w;
			e2[tot].u=i+n,e2[tot].v=j,e2[tot].id=i;
		}
	}
	sort(e2+1,e2+1+tot);
	for(int i=0;i<(1<<k);i++) {
		for(int i=1;i<=n+k;i++) fa[i]=i;
//		cout<<i<<"\n";
		solve(i);
	}
	cout<<ans<<"\n";
}
