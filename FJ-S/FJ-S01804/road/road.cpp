#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,m,k;
struct node{
	int u,v,w;
	bool operator<(const node&W)const{
		return w<W.w;
	}
};
vector<node>g;
int ck[15][10010];
int f[10020];
int cntk[15];

int Find(int x){
	if(f[x]!=x) return f[x]=Find(f[x]);
}

void solve(){
	for(int i=1;i<=n;i++) f[i]=i;
	int sum1=0,sum2=0;
	for(int i=1;i<=k;i++) sum2+=ck[i][0];
	for(int i=0;i<g.size();i++){
		int u=g[i].u,v=g[i].v,w=g[i].w;
		if(Find(u)==Find(v))continue;
		sum1+=w;
		f[v]=u;
		int mn=w,uu=0;
		for(int j=1;j<=k;j++){
			int kw=ck[j][u]+ck[j][v];
			if(Find(j)==Find(u)) kw-=ck[j][u];
			if(Find(j)==Find(v)) kw-=ck[j][v];
			if(mn>kw){
				uu=j;
				mn=kw;
			}
		}
		sum2+=mn;
		cntk[uu]++;
		f[uu]=u;
	}
	for(int i=1;i<=k;i++){
		if(cntk[i]<1) sum2-=ck[i][0];
	}
	cout<<min(sum2,sum1);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	ios::sync_with_stdio(0),std::cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	sort(g.begin(),g.end());
	for(int i=1;i<=k;i++){
		cin>>ck[i][0];
		for(int j=1;j<=n;j++){
			cin>>ck[i][j];
		}		
	}
	solve();
	return 0;
}
