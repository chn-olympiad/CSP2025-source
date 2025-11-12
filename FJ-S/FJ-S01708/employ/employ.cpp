#include <bits/stdc++.h>
using namespace std;
const int N=505,mod=2204128;
int n,m,a[N],f[N],dp[N],sq[N];
long long ans=0;
void dfs(int now,int num,int p){
	if(now==n+1){
		if(num>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		if(dp[now]){
			f[i]=1;
			dfs(now+1,num,p+1);
			f[i]=0;
			continue;
		}
		if(now-1-num<a[i]){
			f[i]=1;
			dfs(now+1,num+1,p);
			f[i]=0;
		}else{
			f[i]=1;
			dfs(now+1,num,p+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char temp;
		cin>>temp;
		if(temp-'0'==0)dp[i]=1;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
