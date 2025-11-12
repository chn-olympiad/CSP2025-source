#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e3+1;
constexpr int mod=998244353;
int n,a[N],s,b[N];
bool vis[N];
inline void dfs(int Item,int k,int sum){
	if (Item==k+1){
		int ans=0,maxn=INT_MIN;
		for (int i = 1;i<=k;i++){
			ans+=b[i];
			maxn=max(maxn,b[i]);
		}
		if (ans>2*maxn) s=(s+1)%mod;
		return;
	}
	for (int i = sum;i<=n;i++){
		if (!vis[i]){
			b[Item]=a[i];
			vis[i]=1;
			dfs(Item+1,k,i);
			vis[i]=0;
		}
	}
}
signed main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cout.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 1;i<=n;i++) cin>>a[i];
	for (int i = 3;i<=n;i++) dfs(1ll,i,1ll);
	cout<<s;
	return 0;
}
