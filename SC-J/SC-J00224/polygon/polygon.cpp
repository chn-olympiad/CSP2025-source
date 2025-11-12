#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
const int M = 1e6 + 5;
const int mod = 998244353;

int K = 0;
int a[N];
long long sum[N];
long long ans = 0;
string ans1[M];

void dfs(int e, int pos, int rmn, long long sum1, string ans2){ //end, position, remain, sum
	if(rmn == 0 && pos >= 0){
		if(sum1 > 2 * a[e]){
			ans ++;
			ans1[++K] = ans2;
			ans %= mod;
		}
		return ;
	}
	if(pos < 0){
		return ;
	}
	dfs(e, pos-1, rmn, sum1, ans2 + to_string(pos));//这个位置不去掉
	dfs(e, pos-1, rmn-1, sum1-a[pos], ans2);//这个位置要去掉 
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	if(n < 3) {
		cout << 0 << '\n';
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n); 
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 3;i <= n;i++){ //枚举最后一个数 
		for(int j = 3;j <= i;j++){ //枚举小木棍的数量 
			dfs(i, i, i - j, sum[i], "");
		}
	}
	int ans3 = unique(ans1 + 1, ans1 + 1 + K) - (ans1 + 1); //去重 
	cout << ans3 % mod << '\n';
	
	return 0;
}