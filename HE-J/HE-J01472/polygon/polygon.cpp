#include <bits/stdc++.h>
using namespace std;
int n, a[50005], dfs[500000005];
bool flag[50005];
int cnt = 0;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= 3; i++){
		int x = 1;
		flag[i] = 1;
		dfs[x++] = i;
		for(int j = 1; j <= 3; j++){
			if(!flag[j]){
				flag[j] = 1;
				dfs[x++] = i;
				for(int k = 1; k <= 3; k++){
					if(!flag[k]){
						flag[x] = 1;
						dfs[x++] = k;
						int maxn = -1;
						int sum = 0;
						for(int y = 1; i <= 3; i++){
							maxn = max(maxn, dfs[y]);
							sum += dfs[y];
						}
						if(sum > 2*maxn){
							cnt++;
						}
						flag[k] = 0;
					}
				}
				flag[j] = 0;
			}
		}
		flag[i] = 0;
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
