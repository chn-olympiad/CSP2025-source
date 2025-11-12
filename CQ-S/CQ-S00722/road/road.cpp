#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=LONG_LONG_MAX,c[11];
bool b[10015];
struct Node{
	long long id,s;
};
vector<Node> g[10015];
map<pair<long long,long long>,bool>bian;
void kfc(long long num,long long aa){
	if(num==k+1){
		bian.clear();
		long long sum=0;
		for(long long i=1;i<=n;i++){
			for(long long k=0;k<g[i].size();k++){
				long long j=g[i][k].id;
				if(bian[{j,i}] || b[j]) continue;
				sum+=g[i][k].s;
				bian[{i,j}]=1;
				//if(aa==1)cout<<i<<" "<<j<<" "<<g[i][k].s<<'\n';
				break;
			}
		}
		ans=min(ans,sum+aa);
		return;
	}
	b[num+10000]=1;
	kfc(num+1,aa);
	b[num+10000]=0;
	kfc(num+1,aa+c[num]);
}
bool cmp(Node a,Node B){
	return a.s<B.s;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long u,v,w,i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long x,j=1;j<=n;j++){
		    cin>>x;
			g[10000+i].push_back({j,x});
			g[j].push_back({10000+i,x});		
		}
	}
	for(long long i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end(),cmp);
	}
	kfc(1,0);
	cout<<ans;
	return 0;
}

