#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10, MAXA = 3e6 + 10;
int s[N], maxx[MAXA], a[N], f[N];
bool vis[MAXA];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		s[i] = s[i - 1] ^ a[i];
	}
	maxx[0] = 0;
	vis[0] = 1;
	for(int i = 1; i <= n; i++){
		f[i] = f[i - 1];
		if(vis[s[i] ^ k]) f[i] = max(f[i], maxx[s[i] ^ k] + 1);
		maxx[s[i]] = max(maxx[s[i]], f[i]);
		vis[s[i]] = 1;
	}
	printf("%d\n", f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}