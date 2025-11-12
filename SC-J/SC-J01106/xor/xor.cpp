#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')	f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')	x = (x<<3) + (x<<1) + (c^48),c = getchar();
	return x * f;
}
const int N = (1<<20)+5;
int n,k,m = N - 5;
int a[N],f[N],g[N];
int vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n = read(),k = read();
	for(int i = 1;i <= n;i++)	a[i] = read(),a[i] ^= a[i-1];
	for(int i = 1;i <= m;i++)	vis[i] = -1;
	for(int i = 1;i <= n;i++){
		int j = vis[a[i] ^ k];
		vis[a[i]] = i;
		if(j != -1)	f[i] = g[j] + 1;
		g[i] = max(g[i-1],f[i]);
	}
	printf("%d\n",g[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}