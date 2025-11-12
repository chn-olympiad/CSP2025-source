#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 510ll;
const int mod = 998244353ll;
int n,m,a[MAXN],ans=0;
int dp[MAXN][MAXN];
bool il[MAXN];
int man[MAXN];
bool vis[MAXN];
void check()
{
	int sum=0;
	for(int j=1;j<=n;j++){
//		cout<<man[j]<<" ";
		if(sum>=a[man[j]]){
			sum++;
		}
		else if(!il[j]){
			sum++;
		}
	}
//	cout<<endl;
	if(n-sum>=m) ans++;
	ans%=mod;
}
void dfs(int x){
	if(x>n){
		check();
		return;
	}
	int sum=0;
	for(int j=1;j<x;j++){
		if(sum>=a[man[j]]){
			sum++;
		}
		else if(!il[j]){
			sum++;
		}
	}
	if(n-sum<m) return;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		man[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","W",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string ls;
	cin>>n>>m>>ls;
	bool flag=1;
	for(int i=0;i<ls.size();i++){
		il[i+1]=(ls[i]=='1');
		flag=flag & ls[i+1];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
 10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
