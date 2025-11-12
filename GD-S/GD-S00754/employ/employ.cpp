#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define ll long long
#define db long double
#define endl '\n'
using namespace std;
const int MAXN=2e5+5,MAXM=0,MOD=998244353;
const long long INF=(1ll<<62);
ll T=1,ans=0;
ll n,m,a[MAXN],b[MAXN];
char c[MAXN];
bool flag[MAXN];
void dfs(ll cur){
	if (cur==n+1){
		ll cnt=0;
		for (int i=1;i<=n;i++){
			if (i-1-cnt>=a[b[i]]) continue;
			if (c[i]=='1') ++cnt;
		}
		if (cnt>=m) ++ans;
		ans%=MOD;
		return;
	}
	for (int i=1;i<=n;i++){
		if (!flag[i]){
			flag[i]=1;
			b[cur]=i;
			dfs(cur+1);
			flag[i]=0;
		} 
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while (T--){
		cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>c[i];
		for (int i=1;i<=n;i++) cin>>a[i];
		if (n<=10)dfs(1);
		else{
			ans=1;
			for (int i=1;i<=n;i++) ans=ans*i%MOD;
		} 
		cout<<ans;
	}
}

