#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int N=1e4+50,M=1e6+50;
int n,m,k;
int c[15],a[15][N];
ll ans;

struct node{
	int x,y,val;
};
vector<node>edg,edgk;

pii f[N<<1];
void init(){
	for(int i=1;i<=n+k;i++)f[i]={i,1};
}
int find(int x){
	if(f[x].first!=x)f[x].first=find(f[x].first);
	return f[x].first;
}
bool merge(int x,int y){
	if(find(x)==find(y))return 0;
	if(f[x].second<f[y].second){
		f[f[x].first]=f[y];
		f[y].second+=f[x].second;
	}
	else{
		f[f[y].first]=f[x];
		f[x].second+=f[y].second;
	}
	
	return 1;
}

bool cmp(node X,node Y){
	return X.val<Y.val;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		edg.push_back({u,v,w});
		ans+=w;
	}
	sort(edg.begin(),edg.end(),cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int i=0;i<(1<<k);i++){
		ll sum=0;
		int cnt=n-1;
		init();
		edgk.clear();
		
		for(int j=1;j<=k;j++){
			if(!(i&(1<<j-1)))continue;
			sum+=c[j]; ++cnt;
			for(int t=1;t<=n;t++){
				edgk.push_back({n+j,t,a[j][t]});
			}
		}
		sort(edgk.begin(),edgk.end(),cmp);
		int p1=0,p2=0;
		while(cnt){
			node t;
			if(edgk.empty()||cmp(edg[p1],edgk[p2]))t=edg[p1++];
			else t=edgk[p2++];
			if(merge(t.x,t.y)){
				sum+=t.val;
				--cnt;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
