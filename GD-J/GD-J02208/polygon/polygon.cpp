#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
const int MOD = 998244353;
const int MAXN = 5005;
int n ;
ll ans = 0;
int a[MAXN];
bool cmp(int pre , int nxt){return pre < nxt;}
ll counter(int m){
	ll cntall = 1;
	ll p = 2;
	for(int i = 2 ; i <= m ; i++){
		cntall += p;
		p *= 2;
	}
	return cntall;
}
void dfs(int x , int sum , int mx){
	sum += a[x];
	if(sum > 2 * mx){
		int teemp = counter(x - 1);
		ans += teemp;
		if(x != 1) ans++;
		ans %= MOD;
		return;
	}
	for(int j = x - 1 ; j >= 1 ; j--){
		dfs(j , sum , mx);
	}
	return;
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		scanf("%d" , &a[i]);
	}
	sort(a + 1 , a + 1 + n , cmp);
	for(int i = n ; i >= 3 ; i--){
		dfs(i , 0 , a[i]);
	}
	cout << ans;
	return 0;
}
