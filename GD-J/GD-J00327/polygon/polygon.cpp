#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int M = 998244353;
int a[N],pre[N];
int n,cnt = 0;
void dfs(int now,int sum,int maxx){
	if(now > n){
		if(sum > maxx * 2) cnt++;
		return;
	}
	dfs(now + 1,sum + a[now],max(maxx,a[now]));
	dfs(now + 1,sum,maxx);
	return;
}
int solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++ ){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	
	if(n <= 20){
		dfs(1,0,0);
		cout << cnt;
		return 0;
	}
	
	int maxx = 0;
	for(int i = 1 ; i + 2 <= n ; i++ ){
		maxx = max(a[i],a[i + 1]);
		for(int j = i + 2 ; j <= n ; j++){
			maxx = max(maxx,a[j]);
			if(pre[j] - pre[i - 1] > maxx * 2) cnt++;
			cnt %= M;
		}
	}
	
	cout << cnt;
	
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
