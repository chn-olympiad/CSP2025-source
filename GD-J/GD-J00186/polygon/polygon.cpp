#include <bits/stdc++.h>
using namespace std;

int n,a[10005],ans=0;
bool vis[10005];
int dp[10005];

void dfs (int ob,int add,int m) {
	if (vis[ob]==true) {
		return;
	}
	if (m>=3 && a[ob]*2<add) {
		for (int i=1;i<=ans;i++) {
			if (add==dp[i]) {
				return;
			}
		}
		
		dp[++ans]=add;
	} 
	
	for (int i=1;i<=n;i++) {
		vis[ob]=true;
		
		dfs(i,add+ob,m++);
		for (int j=i;j<=n;j++) {
			vis[j]=false;
		}
	}
	
	return ;
}

int main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	
	dfs(0,0,0);
	
	cout<<ans;
	return 0;
} 
