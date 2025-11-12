#include <bits/stdc++.h>
using namespace std;
int n,a[5050],num,ti,ans,maxn;
bool vis[5050];
void dfs(int id){
	if(id > n){
		maxn = 0;
		ti = 0;
		num = 0;
		for(int i = 1 ; i <= n ; i++){
			if(vis[i]){
				maxn = max(maxn,a[i]);	
				ti++;
				num+=a[i];
			} 
		}
		if(2*maxn < num && ti >= 3) ans++;
		return;
	}
	vis[id] = 1;
	dfs(id+1);
	vis[id] = 0;
	dfs(id+1);
	return;
} 
int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++) scanf("%d",&a[i]);
	dfs(1);
	cout << ans;
	return 0;
} 