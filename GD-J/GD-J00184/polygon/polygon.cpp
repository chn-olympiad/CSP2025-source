#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5005];
bool f[5005];
long cnt = 0;
const long long Mod = 998244353;
long long mx = 0;

void dfs(int pos, int sum, int num){
	if(pos > n){
		if(num < 3){
			return ;
		}
		bool flag = 0; 
		for(int i = 1; i <= n; i++){
			if(f[i] && sum <= 2 * a[i]){
				flag = 1;
				break;
				
			}
		}
		if(!flag)
		{
			cnt ++;
		}
		return;
	}
	f[pos] = 1;
	dfs(pos + 1, sum + a[pos], num + 1);
	f[pos] = 0;
	dfs(pos + 1, sum, num);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		mx = max(mx, 2 * a[i]);
	}
	if(mx <= 2){
		cout << 0;
		return 0;
	}
	dfs(1, 0, 0);
	cout << cnt % Mod;
	return 0;
} 
