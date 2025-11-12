#include<bits/stdc++.h>
using namespace std;
int n,a[100005][5];
int vis[5];
long long ans=0,cnt=0;
void dfs(int now){
	if(now>n){
		ans=max(ans,cnt);
		return; 
	}
	for(int i=1;i<=3;i++){
		if(vis[i]==n/2)continue;
		vis[i]++;
		cnt+=a[now][i];
		dfs(now+1);
		cnt-=a[now][i];
		vis[i]--;
	}
}
void solve(){
	ans=0,cnt=0;
	memset(vis,0,sizeof(vis));
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i][1] >> a[i][2] >> a[i][3];
	dfs(1);
	cout << ans << endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin >> t;
	while(t--)solve();
	fclose(stdin);
	fclose(stdout);
}
