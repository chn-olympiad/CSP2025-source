#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5010;
const int mod = 998244353;
int n, a[N];
ll cnt=0;
ll j[N];
bool vis[N];
bool isone = 1;
void jc(int x){
	j[1]=1;
	for(int i=2; i<=x; i++){
		j[i] = j[i-1] * i;
	}
	return ;
}
void dfs(int x, int num, ll len, int maxn){
	if(num >=3 && len > 2*maxn){
		cnt++;
		cnt %= mod;
	}
	for(int i=x + 1; i<=n; i++){
		if(vis[i]) continue;
		vis[i] = 1;
		dfs(i, num+1, len+a[i], max(maxn, a[i]));
		vis[i] = 0;
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon,out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(a[i] != 1) isone = 0;
	}
	/*if(isone){
		jc(n);
		for(int i=3; i<=n-1; i++){
			cnt += j[n]/(j[i]*j[n-i]);
			cnt %= mod;
		}
		cout << (cnt+1)%mod;
		return 0;
	}*/
	for(int i=1; i<=n; i++){
		dfs(i, 1, a[i], a[i]);
	}
	cout << cnt%mod; 
	return 0;
}

