#include<bits/stdc++.h>
using namespace std;
int a[5200];
int n,ans;
void dfs(int mg, int zh, int i, int biggest){
	biggest = max(biggest,a[i]);
	if(mg == 1){
		if(2 * biggest < zh + a[i]){
			ans++;
		}
		return ;
	}
	for(int j = 1; i + j < n; ++j){
		dfs(mg - 1, zh + a[i], i + j, biggest);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	fill(a, a + 5201, INT_MAX);
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a,a + 5201);
	for(int i = 3; i <= n; ++i){
		for(int j = 0; j <= n - i; ++j){
			dfs(i, 0, j, -1);
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
