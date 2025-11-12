#include <bits/stdc++.h>
using namespace std;
int a[100005][5];
int vis[100005];
int ans;
int n;
bool check(){
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		mp[vis[i]]++;
	}
	if(mp[1]>n/2 || mp[2]>n/2 || mp[3]>n/2){
		return true;
	}
	return false;
}
void dfs(int x){
	if(x==n+1){
		if(check()){
			return;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i][vis[i]];
		}
		ans=max(ans,sum);
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=2;
	dfs(x+1);
	vis[x]=3;
	dfs(x+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
