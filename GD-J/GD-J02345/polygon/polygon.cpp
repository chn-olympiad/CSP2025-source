#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;int ans;
int a[5005];int b[10];
int k;
void dfs(int x,int cnt,int sum,int maxn){
	if(cnt == k){
		if(sum > maxn*2){ans = (ans+1)%998244353;}
		return;
	}
	for(int i = x+1;i <= n;i++){
		dfs(i,cnt+1,sum+a[i],max(maxn,a[i]));
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 3;i <= n;i++){
		k = i;
		dfs(0,0,0,0);
	}
	cout << ans;
	return 0;
} 
