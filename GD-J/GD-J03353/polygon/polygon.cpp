#include <bits/stdc++.h>
using namespace std;
const int N = 5005, mod = 998244353;
int a[N], s[N], c[N][N], maxn;
int n;
void solveA(){
	if(n <= 2) {
		cout << 0;
		return;
	}
	if(n == 3){
		int maxn = max(a[0], max(a[1], a[2]));
		int sum = a[0]+a[1]+a[2];
		if(sum >= maxn) cout << 1;
		else cout << 0;
		return;
	}
}
void solveB(){
	int ans = 0;
	for(int i = 0; i <= (1<<n);i++){
		int sum = 0, maxn = 0, sides = 0;
		for(int j = 0;j < n;j++){
			if((i>>j)&1){
				sides++;
				sum+=a[j+1];
				maxn = max(maxn, a[j+1]);
			}
		}
		if(sum > maxn*2 && sides >= 3)ans++;
	}
	cout << ans;
}
void solvem1(){
	for(int i = 1;i <= n;i++)c[i][1]=i,c[i][0]=1;
	for(int i = 1;i <= n;i++)c[i][i]=1;
	for(int i = 1;i <= n;i++){
		for(int j = 2;j <= i;j++){
			if(i==j)continue;
			c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
	}
	int sum = 0;
	for(int i = 3;i <= n;i++){
		sum = (sum+c[n][i])%mod;
	}
	cout << sum << endl;
}
void solve(){
	
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool m1 = true;
	int maxn = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i]>1)m1=false;
		maxn = max(maxn, a[i]);
	}
	if(n<=3) solveA();
	else if(n<=20) solveB(); 
	else if(m1) solvem1();
	else solve();
} 
