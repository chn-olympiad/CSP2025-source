#include<bits/stdc++.h>

using namespace std;

int n, a[500005], k, ans;
bool c[500005];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	if(k == 0){
		for(int i = 1; i <= n; i++){
			if(a[i] == 0){
				c[i] = 1;
				ans++;
			}
		}
		for(int i = 1; i <= n; i++){
			if(a[i] == a[i - 1] && !c[i] && !c[i - 1]){
				c[i] = 1;
				c[i - 1] = 1;
				ans++;
			}
		}
		printf("%d", ans);
		return 0;
	}
	if(k == 1){
		for(int i = 1; i <= n; i++){
			if(a[i] == 1) ans++;
		}
		printf("%d", ans);
		return 0;
	}
	return 0;
}
