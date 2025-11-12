#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+15;
int n,m,k;
int f[maxn];
int c[15];
vector<pair<int,int>>e[maxn];
priority_queue<pair<int,int>> q;
bool vis[maxn];
long long ans=0;
int cnt=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		e[t1].push_back({t2,t3});
		e[t2].push_back({t1,t3});
	}
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int t1;
			cin>>t1;
			e[n+i].push_back({j,t1});
			e[j].push_back({n+i,t1+c[i]});
		}
	}
	/*for(int i=1;i<=n+k;i++){
		for(auto y:e[i]){
			cout<<i<<" "<<y.first<<" "<<y.second<<"\n";
		}
	}*/
	q.push({0,1});
	while(!q.empty()&&cnt!=n){
		pair<int,int> awa=q.top();
		q.pop();
		int x=awa.second;
		if(vis[x])continue;
		vis[x]=1;
		if(x<=n)cnt++;
		ans-=awa.first;
	//	cout<<x<<" "<<ans<<"\n";
		for(auto qwq:e[x]){
			if(qwq.first>n)q.push({-qwq.second,qwq.first});
			q.push({-qwq.second,qwq.first});
		}
	}
	cout<<ans;
	return 0;
}
