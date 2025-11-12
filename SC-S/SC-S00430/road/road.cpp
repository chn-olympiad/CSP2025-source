#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e6+5;
int n,m,k;
int d[N];
ll ans=0,sum=0;
int c[15],a[15][N];

int find(int x){
	if(x==d[x]) return x;
	return d[x]=find(d[x]);
}

struct edge{
	int u,v,w;
};
bool cmp(edge x,edge y){
	return x.w<y.w;
}
vector<edge> e,ys;

bool popcount(int x){
	int cnt=0;
	while(x){
		x-=x&-x;
		cnt++;
	}
	return cnt;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) d[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	sort(e.begin(),e.end(),cmp);
	for(edge i:e){
		if(find(i.u)!=find(i.v)){
			ans+=i.w;
			ys.push_back(i);
			d[find(i.u)]=find(i.v);
		}
	}
	for(int i=1;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++) d[j]=j;
		e=ys;
		sum=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				sum+=c[j];
				for(int l=1;l<=n;l++) e.push_back({n+j,l,a[j][l]});
			}
		}
		if(sum>ans) continue;
		sort(e.begin(),e.end(),cmp);
		for(edge i:e){
			if(find(i.u)!=find(i.v)){
				sum+=i.w;
				d[find(i.u)]=find(i.v);
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}