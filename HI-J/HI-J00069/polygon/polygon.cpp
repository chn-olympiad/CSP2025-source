#include <bits/stdc++.h>
using namespace std;

int n,a[5010];
bool vis[5010]; 
long long cnt=0; 

void dfs(int pos){
	if(pos==n+1){
		long long ans = 0;
		int mx = -1,ji=0;
		for(int i=1;i<=n;i++){
			if(a[i]*vis[i]) ji++;
			ans += a[i]*vis[i];
			if(a[i]*vis[i]>mx) mx = a[i]*vis[i];
		}
		if(ans>2*mx&&ji>=3){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	for(int i=0;i<=1;i++){
		vis[pos] = i;
		dfs(pos+1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	dfs(1);
	
	cout << cnt%998244353;
	
	return 0;
} 
