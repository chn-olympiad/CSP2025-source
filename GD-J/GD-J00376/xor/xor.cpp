#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 7;
int n;
ll k;
ll a[N], c[N];
int f[N], ans;
map<ll, int>mp;
map<ll, bool>vis;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%lld", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		c[i] = c[i - 1] ^ a[i]; 
	}
	vis[0] = 1;
	for(int i = 1; i <= n; i++){
		f[i] = ans;
		int j = mp[k ^ c[i]];
		if(vis[k ^ c[i]] && f[j] == ans){
			f[i] = ans + 1;
			ans++;
		}
		if(f[i] > f[mp[c[i]]]) mp[c[i]] = i;
		vis[c[i]] = 1;
	}
	printf("%d\n", ans);
	return 0;
}
