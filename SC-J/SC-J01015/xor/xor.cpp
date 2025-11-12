#include<bits/stdc++.h>
using namespace std;

const int N = 4194304;

int tj[N];
int f[N], n, k, a[N];
int jj[N];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i ++){
		scanf("%d", &a[i]);
	}
	
	for(int i = 1;i <= n;i ++){
		a[i] ^= a[i - 1];
	}
	for(int i = 1;i <= 3194304;i ++)tj[i] = -1;
	for(int i = 1;i <= n;i ++){
		int x = a[i] ^ k;
		if(tj[x] == -1){
			jj[i] = -1;
		}
		else jj[i] = tj[x] + 1;
		tj[a[i]] = i;
	}
	
	for(int i = 1;i <= n;i ++){
		f[i] = f[i - 1];
		if(jj[i] != -1){
			f[i] = max(f[i], f[jj[i] - 1] + 1);
		}
	}
	
	printf("%d\n", f[n]);
	
	return 0;
}