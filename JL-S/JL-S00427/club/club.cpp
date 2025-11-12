#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],cnt,vis[5],sum,ans[5],xx;
void dfs(int id){
	if(id == n+1){
		sum = max(sum,xx);
		return ;
	}
	
	for(int i = 1;i <= 3;i++){
		if(a[id][i] > a[id][i-1]){
			cnt = i;
		}
	}
	if(vis[cnt] <= n/2){
		vis[id]+=1;
		xx += a[id][cnt];
		dfs(id+1);
		vis[id]-=1;
		xx -= a[id][cnt];
	}
	dfs(id+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int l = 1;l <= t;l++){
		cin >> n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> a[i][j];
			}
		}
		dfs(1);
		ans[l] = sum;
		sum = 0;
	}
	for(int i = 1;i <= t;i++){
		cout << ans[i] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
