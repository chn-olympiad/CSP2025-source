#include<bits/stdc++.h>
#define endl '\n'
#define MOD 998244353
using namespace std;
int n, ans, a[5005], sum[5005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++)
		sum[i] = sum[i - 1] + a[i];
	for(int i = 1;i <= n;i++){
		for(int j = i + 2;j <= n;j++){
			if(sum[j] - sum[i - 1] > a[j] * 2)
				ans = (ans + 1) % MOD;
		}
	}
	cout << ans * 1.5 << endl;
	return 0; 
}

// Wo Chang Chang Zhui Yi Guo Qu (
// 怎么又和小木棍见面了 /fn 
// 为什么比赛时外面有人在跳广场舞 /yiw 
