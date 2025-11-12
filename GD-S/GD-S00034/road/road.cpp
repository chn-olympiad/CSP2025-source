#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define endl '\n'
using namespace std;
constexpr int N=1e4+10,M=1e6+10;
int n,m,k;
int c[15],a[15][N],fa[N];
struct E{
	int u,v,w;
	bool operator<(const E &a)const{
		return w<a.w;
	}
}Edge[M+100000];
int get(int x){
	return (fa[x]==x)?x:fa[x]=get(fa[x]);
}
namespace stk1{
	void solve(){
		sort(Edge+1,Edge+1+m);
		ll ans=0;
		int cnt=n;
		for(int i=1;i<=m;i++){
			int u=get(Edge[i].u),v=get(Edge[i].v),w=Edge[i].w;
			if(u^v){
				fa[u]=v;
				ans+=w;
				--cnt;
				if(cnt==1)break;
			}
		}
		cout<<ans<<endl;
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>Edge[i].u>>Edge[i].v>>Edge[i].w;
	}
	bool flga=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])flga=0;
		int q=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0)q=1;
		}
		if(!q)flga=0;
	}
	if(k==0)return stk1::solve(),0;
	if(flga){
		for(int i=1;i<=k;i++){
			int s=0;
			for(int j=1;j<=n;j++)
				if(a[i][j]==0){
					s=j;
					break;
				}
			for(int j=1;j<=n;j++)
				if(s!=j)Edge[++m]={s,j,a[i][j]};
		}
		return stk1::solve(),0;
	}



	return 0;
}

