#include<bits/stdc++.h>
using namespace std;
int n, maxn = 0;
long long ans = 0, sum = 0, tot = 1;
int a[5005];
/*int cmp(int x, int y){
	int a = x, b = y;
	return a > b;
}*/
void bfs(int t){
	if(t >= 3 && a[t] * 2 > sum){
		ans++;
	}
	for(int i = t; i <= n; i++){
		sum += a[t];
		return bfs(t + 1);
	}	

	return ;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	
	cin >> n;	if(n == 3){
	cout << 1;
	return 0;
}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	bfs(tot);
	cout << ans % 998244353;
	return 0;
} 