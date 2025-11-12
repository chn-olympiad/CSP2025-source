#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt;
map<vector<int>,bool > vis;
void dfs(int x,int k,int sum,int mx,vector<int> f){
	if(k>=3 && sum>2*mx && !vis[f]) {
		cnt++;
		cnt%=998244353;
		vis[f]=1;
	}
	if(x==n+1) return ;
	dfs(x+1,k,sum,mx,f);
	f.push_back(x);
	dfs(x+1,k+1,sum+a[x],max(mx,a[x]),f);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(0);
	vector<int> ff;
	cin>>n;
	if(n>20) {
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0,ff);
	cout<<cnt;
	return 0;
}