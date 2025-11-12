#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005], q[500005];
long long res;bool vis[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", a + i);	
		q[i] = a[i] ^ q[i - 1];
	} 
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			bool flag = 0;
			for(int x = i; x <= j; x++) if(vis[x]) {flag = 1;break;}
			if(flag) continue;
			int k1 = q[j] ^ q[i - 1];
			if(k1 == k){
				res++;
				for(int x = i; x <= j; x++) vis[x] = 1;
			} 
		}
	}
	printf("%lld", res);
	return 0;
}

