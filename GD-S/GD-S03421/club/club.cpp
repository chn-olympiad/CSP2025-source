#include<bits/stdc++.h>
using namespace std;

void sol11(int n){
	int na[1086], nb[1086], nc[1086];
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &na[i], &nb[i], &nc[i]);
	}
	int n222 = n / 2;
	int f[186][186][186];
	for(int k = 1; k <= n; k++){
		for(int i = 0; i <= n222; i++){
			for(int j = 0; j <= n222; j++){
				int t = k - i - j;
				if(t > n222) continue;
				f[i][j][t] = 0;
				if(i>0) f[i][j][t] = max(f[i][j][t], f[i-1][j][t] + na[k]);
				if(j>0) f[i][j][t] = max(f[i][j][t], f[i][j-1][t] + nb[k]);
				if(t>0) f[i][j][t] = max(f[i][j][t], f[i][j][t-1] + nc[k]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= n222; i++){
		for(int j = 0; j <= n222; j++){
			int t = n - i - j;
			if(t > n222) continue;
			ans = max(ans, f[i][j][t]);
		}
	}
	printf("%d\n", ans);
	return;
}

void sol20(int n){
	int n222 = n / 2;
	int na[100086], nb[100086], nc[100086];
	bool flaga = 1, flagb = 1;
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &na[i], &nb[i], &nc[i]);
		if(nb[i]) flaga = 0;
		if(nc[i]) flaga = flagb = 0;
	}
	
	if(flaga){
		int ans = 0;
		sort(na+1, na+1+n);
		for(int i = n; i > n222; i--){
			ans += na[i];
		}
		printf("%d\n", ans);
		return;
	}
	
	
	int f[5086][5086];
	for(int i = 0; i <= n222; i++){
		for(int j = 0; j <= n222; j++){
			f[i][j] = 0;
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = n222; i >= 0; i--){
			if(i > k) continue;
			for(int j = n222; j >= 0; j--){
				if(i + j > k) continue;
				int t = k - i - j;
				if(t > n222) continue;
				if(t>0) f[i][j] += nc[k];
				if(i>0) f[i][j] = max(f[i][j], f[i-1][j] + na[k]);
				if(j>0) f[i][j] = max(f[i][j], f[i][j-1] + nb[k]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= n222; i++){
		for(int j = 0; j <= n222; j++){
			int t = n - i - j;
			if(t > n222) continue;
			ans = max(ans, f[i][j]);
		}
	}
	printf("%d\n", ans);
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T, N;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		else sol20(N);
	}
	return 0;
}
