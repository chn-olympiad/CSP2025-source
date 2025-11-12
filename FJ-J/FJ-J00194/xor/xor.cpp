#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;

int n, k;
int a[maxn];

void read(int &x){
	x = 0;
	int f = 1;
	char c = getchar();
	while (!isdigit(c)){
		if (c == '-'){
			f = 1;
		}
		c = getchar();
	}
	while (isdigit(c)){
		x = x * 10 + c - 48;
		c = getchar();
	}
	x *= f;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	read(n), read(k);
	bool flag_texta = 1;
	bool flag_textb = 1;
	bool flag_textc = 1;
	for (int i = 1; i <= n; ++i){
		read(a[i]);
		if (a[i] != 1){
			flag_texta = 0;
		}
		if (a[i] > 1){
			flag_textb = 0;
		}
		if (a[i] > 255){
			flag_textc = 0;
		}
	}
	// 特殊性质A 
	if (flag_texta){
		cout << n / 2;
		return 0;
	} 
	// 特殊性质B 
	if (flag_textb){
		if (k == 1){
			int ans = 0;
			for (int i = 1; i <= n; ++i){
				if (a[i] == 1){
					ans++;
				}
			}
			cout << ans << "\n";
			return 0;
		}
		else if (k == 0){
			int ans = 0;
			for (int i = 1; i <= n; ++i){
				if (a[i] == 1){
					ans++;
				}	
			}
			cout << ans / 2 << "\n";
			return 0;
		}
	}
	if (flag_textc){
		int pipei[maxn];
		int pipei2[maxn];		
		memset(pipei, 0, sizeof(pipei));
		memset(pipei2, 0, sizeof(pipei2));
		for (int i = 1; i <= n ; ++i){
			pipei[i] = pipei2[a[i]];
			pipei2[a[i]] = i;			
		}
		int dp[maxn];
		memset(dp, 0,sizeof(dp));
		for (int i = 1; i <= n; ++i){
			dp[i] = max(dp[i - 1], dp[pipei[i]] + 1);
		}
		cout << dp[n];
		
	}
	return 0;
}
