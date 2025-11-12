#include <bits/stdc++.h>
using namespace std;

int n,mm,sum,maxn,ans;
int a[5005],sumii[5005];

void dfs(int m){
	if(m == n+1){
		if(mm >= 3 && sum > maxn*2)
			ans++;
		return;
	}
	if(mm+n-m+1 >= 3 && sum+sumii[n]-sumii[m-1] > maxn*2){
		int mx = maxn;
		mm++;
		sum += a[m];
		maxn = max(maxn,a[m]);
	
		dfs(m+1);
	
		mm--;
		sum -= a[m];
		maxn = mx;
	}
	dfs(m+1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sumii[i] = sumii[i-1] + a[i];
	}
	dfs(1);
	cout << ans;
	
	return 0;
}
