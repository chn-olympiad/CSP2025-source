#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
vector<pair<long long,long long>> mapp[1020];
vector<long long> vis;
vector<pair<string,long long>> mppa[1020];
long long b[20];
long long ans = LLONG_MAX;
long long zg = 0;
long long dfs(long long s,long long mo,string zt,long long gzs){
	if(mo >= ans && zg != n + gzs){
		return -1;
	}
	for(auto i : mppa[s]){
		if(i.first == zt){
			ans = min(ans,mo + i.second);
			return i.second;
		}
	}
	vis[s] = mo;
	zg++;
	long long cc = 0;
	for(auto i : mapp[s]){
		if(vis[i.first] > mo + i.second + (i.first > n ? (zt[i.first - n] == '1' ? 0 : b[i.first - n]) : 0)){
			string czt = zt;
			long long cgzs = gzs;
//			for(int i = 0;i <= 19;i++){
//				printf("%c",zt[i]);
//			}
//			printf("\n");
			long long hc1 = i.second + (i.first > n ? (zt[i.first - n] == '1' ? 0 : b[i.first - n]) : 0);
			if(i.first > n && zt[i.first - n] != '1'){
				czt[i.first - n] = '1';
				cgzs++;
			}
			long long y = dfs(i.first,mo + hc1,czt,cgzs);
			if(y != -1){
				cc = min(cc,y + hc1);
			}
		}
	}
	if(zg == n + gzs){
		ans = min(ans,mo);
	}
	return cc;
	mppa[s].push_back({zt,cc});
	vis[s] = LLONG_MAX;
	zg--;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(long long i = 1;i <= m;i++){
		long long u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		mapp[u].push_back({v,w});
		mapp[v].push_back({u,w});
	}
	for(long long i = 1;i <= k;i++){
		scanf("%d",&b[i]);
		for(long long j = 1;j <= n;j++){
			long long w;
			scanf("%d",&w);
			mapp[n + i].push_back({j,w});
			mapp[j].push_back({n + i,w});
		} 
	}
	for(long long i = 1;i <= n + k;i++){
		vis.push_back(LLONG_MAX);
	}
	dfs(1,0,"00000000000000000000",0);
	cout<<ans;
	return 0;
}

