#include <bits/stdc++.h>
using namespace std;
const int mod1=998,mod2=244,mod3=353;
int ans=0;
int n;
int a[5005];
void dfs(int x,int mx,long long sum,int shu){
	if(x==n){
		if(sum>2*mx && shu>=3){
			ans++;
			ans=ans%mod1%mod2%mod3;
		} 
		return;
	}
	dfs(x+1,max(mx,a[x+1]),sum+a[x+1],shu+1);
	dfs(x+1,mx,sum,shu);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,0,0);
	cout << ans%mod1%mod2%mod3;
	return 0;
}
