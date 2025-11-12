#include<bits/stdc++.h>//kruscal
using namespace std;
const int N=1e6+5;
#define ll long long
int cnt,n,m,k,fa[N],c[N];
ll ans=1e18,w[15][N];
bool s[15];
struct edg{
	int u,v;ll w;
}a[N];
vector<edg> e;
int find(int x){
	return x==fa[x]? fa[x]:fa[x]=find(fa[x]);
}
void uni(int x,int y){
	x=find(x);y=find(y);
	fa[x]=y;
}
bool cmp(edg a,edg b){
	return a.w<b.w;
}

void solve(int tex){
	ll _ans=0;
	e.clear();
	memset(s,0,sizeof s);
	for(int i=1;i<N;i++)fa[i]=i;
	for(int i=1;i<=m;i++)e.push_back((edg){a[i].u,a[i].v,a[i].w});
	for(int i=1;i<=k;i++)
		if(tex&(1<<(i-1)))s[i]=1;
	for(int i=1;i<=k;i++){
		if(s[i]){
			_ans+=c[i];
			for(int j=1;j<=n;j++)
				e.push_back((edg){i+n,j,w[i][j]});
		}
	}
	if(_ans>ans)return ;
	sort(e.begin(),e.end(),cmp);
	cnt=e.size();
	for(int i=0;i<cnt;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			uni(x,y);
			_ans+=e[i].w;
			if(_ans>ans)return ;
		}
	}
	ans=min(ans,_ans);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;ll w;
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w[i][j];
		}
	}
	int tot=(1<<k)-1;
	for(int i=0;i<=tot;i++){
		solve(i);
	}
	cout<<ans<<'\n';
	
	return 0;
}
