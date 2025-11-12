#include <bits/stdc++.h>
using namespace std;
long long a[5005];
int v[5005];
long long cnt = 0;
long long he[5005];
int dfs(int u, long long zong, int n){
	if (zong > a[u] * 2){
		cnt ++;
		cnt = cnt % 998244353;
		//cout << zong << " " << a[u] << endl;
	}if (u > n || he[n] <= a[u - 1] * 2){
		//cout << zong << " " << a[u] << endl;
		return 0;
	}
	for (int i = u + 1; i <= n;i++){
		if (!v[i]){
			v[i] = 1;
			dfs(i, zong + a[i], n);
			v[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int max_a = -1;
	cin >> n;
	he[0] = 0;
	for (int i = 1; i <= n ;i++){
		cin >> a[i];
		he[i] = he[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	if (n == 3){
		if (a[1] + a[2] + a[3] > a[3] * 2){
			cout << 1;
		}else {
			cout << 0;
		}
	}else if(a[n] == 1 && n >= 500){
		for (int i = 1; i <= n - 2;i++){
			for (int j = i; j <= n - 2;i++){
				cnt += i;
			}	
		}
		cout << cnt;
	}else{
		for(int i = 1; i < n - 1; i++){
			dfs(i,a[i],n);
		}
		cout << cnt;
	}
	return 0;
}

// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
