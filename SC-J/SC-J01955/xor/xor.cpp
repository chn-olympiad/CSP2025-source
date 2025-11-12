#include <bits/stdc++.h>
#define int long long
using namespace std;
/*!@#$%^&*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
const int N=5e5+5;
int n,k;
int a[N];
int u[1<<21];
int f[N],g[N];//g为f的前缀和
/*!@#$%^&*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/

/*!@#$%^&*!@#$%^&*~~ Boundary Line ~~*&^%$#@!*&^%$#@!*/
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int xum=0;
	memset(u,-1,sizeof u);
	u[0]=0;
	for(int i=1;i<=n;i++){
		xum^=a[i];
		u[xum]=i;
		if(u[xum^k]!=-1)
			f[i]=g[u[xum^k]]+1;
		g[i]=max(g[i-1],f[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
/*
4 2 
2 1 0 3

4 0
2 1 0 3

4 3
2 1 0 3

先考虑DP，f[i]=sum(f[1]+f[2]+···+f[j]) (^(j+1···i) == k)
g[i]为f[]前缀和
令u[i]为从1开始的异或和为i的最大下标
*/