#include<bits/stdc++.h>
using namespace std;

bool flag;
long long ans,as;
int n,m,k,u,v,w,c,t[10010];
int mp[10010][10010];

void dfs(int st,int sp,long long step){
	if(st == sp){
		as = min(ans,step);
	}
	if(!flag) return;
	flag = false;
	for(int i = 1;i <= n;i++){
		if(st == i) continue;
		dfs(i,sp,step += mp[i][sp]);
	}
	flag = true;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		cin>>u>>v>>w;
		mp[u][v] = mp[v][u] = w;
	}
	for(int i = 1;i <= k;i++){
		cin>>c;
		for(int j = 1;j <= n;j++){
			cin>>t[i];
			
		}
		for(int k = 1;k <= n;k++){
			for(int l = k;l <= n;l++){
				if(k == l) continue;
				if(mp[k][l] == 0){
					mp[k][l] = mp[l][k] = t[k] + t[l] + c;
				}else{
					mp[k][l] = mp[l][k] = min(mp[k][l],t[k] + t[l] + c);
				}
			}
		}
	}
	
	return 0;
}
