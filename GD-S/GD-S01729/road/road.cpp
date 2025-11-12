#include<bits/stdc++.h>
using namespace std;
const int maxm=1e6+15,maxk=1e1+5;
long long n,m,k,u,v,w,s,c[maxk],Min=LONG_MAX;
bool b[maxm];
struct node{
	long long tong,qian;
};
vector<node>vec[maxm];
void dfs(long long x,long long cnt,long long sum){
	if(cnt==n){
		Min=min(Min,sum);
		return;
	}
	for(auto sss:vec[x]){
		if(b[sss.tong])continue;
		b[sss.tong]=true;
		if(sss.tong>n)dfs(sss.tong,cnt,sum+c[sss.tong-n]+sss.qian);
		else dfs(sss.tong,cnt+1,sum+sss.qian);
		b[sss.tong]=false;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			vec[n+i].push_back({j,w});
			vec[j].push_back({n+i,w});
		}
	}
	b[1]=true;
	dfs(1,1,0);
	cout<<Min<<'\n';
	return 0;
}
