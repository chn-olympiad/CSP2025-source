#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
int cnt[5005];
bool vis[5005];
int n;
int a[5005];
int dfs(int now,int m){
	int ans = 0;
	if(now == m + 1){
		int all = 0,maxn = -2147483647;
		for(int i = 1;i <= m;i ++){
			all += a[cnt[i]];
			maxn = max(maxn,a[cnt[i]]);
			//cout << cnt[i] << ' ';
		}
		//cout << endl;
		if(all > 2 *maxn) return 1;
	}else{
		for(int i = cnt[now - 1] + 1;i <= n;i ++){
			if(!vis[i]){
				cnt[now] = i;
				vis[i] = 1;
				ans += dfs(now + 1,m);
				vis[i] = 0;
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++)cin >> a[i];
    long long ra = 0;
    for(int i = 3;i <= n;i ++)
    {
		ra += dfs(1,i);
		memset(vis,0,sizeof(vis));
	}
    cout << ra % 998244353;
	return 0;
}
