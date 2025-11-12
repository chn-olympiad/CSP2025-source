#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m, ans, sum, op[505];
bool flag;
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	flag = 1, sum = n;
	for(int i = 1;i <= n;i++){
		cin >> op[i];
		if(s[i - 1] != 0)flag = 0;
		if(op[i] == 0)sum--;
	}
	if(sum < m)cout << 0;
	else if(flag){
		ans = 1;
		for(int i = 2;i <= n;i++)ans = (ans * i) % MOD;
		cout << ans;
	}
	else if(m == n)cout << 0;
	else if(m == 1){
		
	}
	return 0;
}

