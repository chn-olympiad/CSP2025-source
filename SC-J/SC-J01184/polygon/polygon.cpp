#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10,M = 998244353;
typedef long long ll;
ll n,a[N],sum=0;

void dfs(ll u,ll num,ll mx){
	if(u>n) return;
	for(ll i=u;i<=n;i++){
		if((mx+a[i])>(2*a[i])&&num>2){
			sum++;
			sum%=M;
		}
		dfs(i+1,num+1,mx+a[i]);
	}
}

void solve(){
	cin >> n;
	for(ll i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		dfs(i+1,2,a[i]);
	}
	cout << sum%M << '\n';
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}