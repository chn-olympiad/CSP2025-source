//永世传颂，不休独舞，神爱众人，芙门永存！
#include <bits/stdc++.h>
#define I_love_Furina return
#define int long long
using namespace std;
const int N = 1e5 + 5;
int Furina(){
	int x = 0; bool f = 0; char c = getchar();
	while(c < '0' || c > '9'){ if(c == '-') f = 1; c = getchar(); }
	while(c >= '0' && c <= '9'){ x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	I_love_Furina f ? -x : x;
} 
void fufu(int f){
	if(f < 0){ putchar('-'); f = -f; }
	if(f < 10) putchar(f + '0');
	else{ fufu(f / 10); putchar(f % 10 + '0'); }
}
int t, n, a[N][4], dp[N][4];
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = Furina();
	while(t--){
		n = Furina();
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 3; j++)
				a[i][j] = Furina();
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 3; j++) 
				dp[i][j] = max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][3])) + a[i][j];
		fufu(max(dp[n][1], max(dp[n][2], dp[n][3])));
		putchar('\n');
	}
	I_love_Furina 0;
}
