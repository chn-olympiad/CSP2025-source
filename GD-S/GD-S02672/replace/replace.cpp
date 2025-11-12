#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0, f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f = -1;ch = getchar();}
	while(isdigit(ch)){s = s * 10 + ch - '0';ch = getchar();}
	return s * f;
}
const int MAXN = 3e6 + 5, MR = 5e6 + 5, E = 1909, MOD = 911451407;
int n, q, flag = 1, hsh[MAXN], hsh2[MAXN], a[MAXN];
int Hsh[MAXN], Hsh2[MAXN], pw[MAXN];
char ch[MAXN], ch2[MAXN];
int query(int l, int r){
	return ((Hsh[r] - Hsh[l - 1] * pw[r - l + 1] % MOD) % MOD + MOD) % MOD;
}
int query2(int l, int r){
	return ((Hsh2[r] - Hsh2[l - 1] * pw[r - l + 1] % MOD) % MOD + MOD) % MOD;
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), q = read();
	pw[0] = 1;
	for(int i = 1;i < MAXN;i ++)pw[i] = pw[i - 1] * E % MOD;
	for(int i = 1;i <= n;i ++){
		scanf("%s", ch + 1);
		int len = strlen(ch + 1);
		for(int j = 1;j <= len;j ++)hsh[i] = (hsh[i] * E % MOD + ch[j] - 'a' + 1) % MOD;
		scanf("%s", ch + 1);
		for(int j = 1;j <= len;j ++)hsh2[i] = (hsh2[i] * E % MOD + ch[j] - 'a' + 1) % MOD;
		a[i] = len;
	}
	while(q --){
		scanf("%s%s", ch + 1, ch2 + 1);
		int len = strlen(ch + 1), res = 0;
		for(int i = 1;i <= len;i ++)Hsh[i] = (Hsh[i - 1] * E % MOD + ch[i] - 'a' + 1) % MOD;
		for(int i = 1;i <= len;i ++)Hsh2[i] = (Hsh2[i - 1] * E % MOD + ch2[i] - 'a' + 1) % MOD;
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= len - a[i] + 1;j ++){
				if(hsh[i] == query(j, j + a[i] - 1) && hsh2[i] == query2(j, j + a[i] - 1)){
					if(query(1, j - 1) == query2(1, j - 1) && query(j + a[i], len) == query2(j + a[i], len))res ++;
				}
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}

