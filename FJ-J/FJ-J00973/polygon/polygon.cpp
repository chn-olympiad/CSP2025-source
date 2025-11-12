#include <bits/stdc++.h>
using namespace std;
int a[5005];
int vis[5005];
long long s = 0, z = 0;
int n;

int qb(){
	for(int i = 2; i <= n; i++){
		if(a[i] != a[i - 1]){
			return 0;
		}
	}
	return 1;
}

void dfs(int x){
	if(x > n){
		int e = 0;
		int s = 0;
		int c = 0;
		for(int i = 1; i <= n; i++){
			if(vis[i]){
				s += a[i];
				e = a[i];
				c++; 
			}
		}
		if(s > e * 2 && c >= 3){
			z++;
			z %= 998244353;
		}
		return;
	}
	vis[x] = 1;
	dfs(x + 1);
	vis[x] = 0;
	dfs(x + 1);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if(!qb()){
		dfs(1);
	}else{
		long long z = 1;
		for(int i = 1; i <= n; i++){
			z *= 2;
			z %= 998244353;
		}
		z -= 7;
		for(int i = 5; i <= n + 1; i++){
			z -= i;
			z++; 
		}
		cout << z;
		return 0;
	}
	cout << z;
	return 0;
}
