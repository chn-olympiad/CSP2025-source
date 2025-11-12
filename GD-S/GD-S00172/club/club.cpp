#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[N][5], mem[5];
long long sum, res;

void dfs(int u){
	if(u == n){
		res = max(res, sum);
		return;
	}
	for(int i = 1; i <= 3; i++)
		if((mem[i] + 1) * 2 <= n){
			sum += a[u][i];
			mem[i]++;
			dfs(u + 1);
			sum -= a[u][i];
			mem[i]--;
		}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		
		sum = res = 0;
		memset(mem, 0, sizeof mem);
		cin >> n;
		for(int i = 0; i < n; i++)
			for(int j = 1; j <= 3; j++) cin >> a[i][j];
		if(n <= 30) dfs(0);
		else{
			int tmp[N];
			for(int i = 0; i < n; i++) tmp[i] = a[i][1];
			sort(tmp, tmp + n);
			for(int i = n - 1; i >= n / 2; i--) res += tmp[i];
		}
		cout << res << endl;
		
	}
	return 0;
}
