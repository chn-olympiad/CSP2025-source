#include<bits/stdc++.h>
using namespace std;
int n;
long long a[10000],b[10000];
long long ans;
bool st[10000];
void dfs(int u,int k){
	if (u == k + 1){
		long long maxn = -1,sum = 0;
		for (int i = 1;i <= k;i++)
			maxn = max(maxn,a[b[i]]),sum += a[b[i]];
		if (sum > maxn * 2) ans = (ans + 1) % 998244353;
		return ;
	}
	for (int i = b[u - 1] + 1;i <= n;i++)
		if (!st[i]){
			st[i] = 1;
			b[u] = i;
			dfs(u + 1,k);
			st[i] = 0;
		}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++)
		cin>>a[i];
	for (int i = 3;i <= n;i++){
		memset(st,0,sizeof st);
		dfs(1,i);
	}
	cout<<ans;
	return 0;
}

