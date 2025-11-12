#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[5006],MOD=998244353,n,ans;
void dfs(ll di,ll len,ll sum){
	for(int i=di+1;i<=n;i++){
		if(len>=2&&sum>a[i]){
			ans++;
			ans=ans%MOD;
		}
		dfs(i,len+1,sum+a[i]);
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<ans%MOD;
	return 0;
} 
