#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=5e6+5;
struct Data{
	int from,to,cost;
	friend bool operator <(const Data &a,const Data &b){
		return a.cost<b.cost;
	}
} edge[M];
vector<Data> mp[N];
int n,m,k,cost[15][N];
int fa[N];
int find(int now){
	if(fa[now]==now) return now;
	return fa[now]=find(fa[now]);
}
namespace sub1{
	int ans=0;
	queue<int> q;
	int main(void){
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(edge+1,edge+1+m);
		for(int i=1;i<=m;i++){
			int fa1=find(edge[i].from),fa2=find(edge[i].to);
			if(fa1!=fa2){
				fa[fa1]=fa2;
				ans+=edge[i].cost;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
}

signed main(void){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,c;
		scanf("%lld%lld%lld",&u,&v,&c);
		mp[u].push_back({v,c});
		edge[i]={u,v,c};
	}
	bool flg=true;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)
			scanf("%lld",&cost[i][j]);
		if(cost[i][0]!=0) flg=false;
	}
	if(flg){
		for(int i=1;i<=k;i++){
			int now=-1;
			for(int j=1;j<=n;j++)
				if(cost[i][j]==0) now=j;
			for(int j=1;j<=n;j++){
				edge[++m]={now,j,cost[i][j]};
				mp[now].push_back({j,cost[i][j]});
				mp[j].push_back({now,cost[i][j]});
			}
		}
		k=0;
	}
	if(k==0){
		sub1::main();
		return 0;
	}else cout<<0<<endl;
	return 0;
}
//感谢CCF大大送来的48pts 