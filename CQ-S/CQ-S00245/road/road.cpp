#include<bits/stdc++.h>
#define mk make_pair
using namespace std;
mt19937 engine(chrono::steady_clock().now().time_since_epoch().count());
const int MAXK=15;
const int MAXN=1e4+15;
const int MAXM=1e6+15;
int n,m,k;
int c[MAXK],cnt[MAXK];
struct Edge {
	int u,v,val;
	bool operator < (const Edge &oth) const {
		return val<oth.val;
	}
}a[MAXM],b[MAXK][MAXN],cpy[MAXK][MAXN];
struct DSU {
	int fa[MAXN],siz[MAXN];
	void init() {
		for(int i=1;i<=n+k;i++) {
			fa[i]=i,siz[i]=1;
		}
	}
	int find(int x) {
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	bool merge(int x,int y) {
		if((x=find(x))==(y=find(y))) return false;
		if(siz[x]<siz[y]) swap(x,y);
		fa[y]=x,siz[x]+=siz[y];
		return true;
	}
}dsu;
long long ans;
void DFS(int pos,int id,long long res)
{
//	cerr<<"DFS : "<<pos<<" , "<<id<<" and "<<res<<"\n";
	if(pos) {
		dsu.init();
		res+=c[pos];
		long long Ans=res;
		cnt[pos]=0;
		int l=1,r=1;
		while(l<=cnt[id]||r<=n) {
			if(r>n||(l<=cnt[id]&&cpy[id][l]<b[pos][r])) {
				if(dsu.merge(cpy[id][l].u,cpy[id][l].v)) {
					Ans+=cpy[id][l].val;
					cpy[pos][++cnt[pos]]=cpy[id][l];
				}
				l++;
			}
			else {
				if(dsu.merge(b[pos][r].u,b[pos][r].v)) {
					Ans+=b[pos][r].val;
					cpy[pos][++cnt[pos]]=b[pos][r];
				}
				r++;
			}
		}
		ans=min(ans,Ans);
	}
	for(int i=pos+1;i<=k;i++) {
		DFS(i,pos,res);
	}
}
long long Solve()
{
	cnt[0]=0;
	dsu.init();
	for(int i=1;i<=m;i++) {
		if(dsu.merge(a[i].u,a[i].v)) {
			ans+=a[i].val;
			cpy[0][++cnt[0]]=a[i];
		}
	}
//	cerr<<"ans : "<<ans<<"\n";
	DFS(0,0,0);
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		cin>>a[i].u>>a[i].v>>a[i].val;
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			int val;
			cin>>val;
			b[i][j]=(Edge){n+i,j,val};
		}
		sort(b[i]+1,b[i]+n+1);
	}
	cout<<Solve()<<"\n";
	return 0;
}
