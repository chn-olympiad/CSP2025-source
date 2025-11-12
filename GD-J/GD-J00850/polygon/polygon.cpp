#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef double dou;

const int N = 1e4 + 10;

ll n,ans;
ll a[N];

void dfs(ll pos,ll sum){
	if(pos>n)
		return;
	if(sum+a[pos]>a[pos]*2) ans++;
	ans %= 998244353;
	dfs(pos+1,sum+a[pos]);
	dfs(pos+1,sum);
}

void solve(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	dfs(1,0);
	cout << ans;
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
