#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
int n, m, ans, c[505], p[505];
char s[505];
void dfs(int arr[], int b[], int vis[], int pos){
	if(pos == n+1){
		int v = 0, a = 0;
		for(int i = 1; i <= n; i++){
			if(s[i] == '0' or v >= b[i]){
				v++;
			}else{
				v = 0;
				//printf("%d '%c'\n", arr[i], s[i]);
				a++;
			}
		}
		//cout << endl;
		if(a >= m){
			ans++;/*
			cout << "a = " << a << endl;
			for(int i = 1; i <= n; i++){
				printf("%d ", arr[i]);
			}
			cout << endl;*/
		}
		//cout << endl;
		return;
	}
	for(int i = 1; i <= n; i++){ 
		if(vis[i] == 0){
			arr[pos] = p[i];
			b[pos] = c[i];
			vis[i] = 1;
			dfs(arr, b, vis, pos + 1);
			vis[i] = 0;
		}
	}
	return;
}
int main(void){
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int arr[505] = {0}, vis[505] = {0}, b[505] = {0};
	cin >> n >> m;
	for(int i = 1; i <= n+1; i++){
		s[i] = getchar();
		p[i] = i;
	}
	s[n+1] = '\0';
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}
	dfs(arr, b, vis, 1);
	cout << ans;
	
	return 0;
}
