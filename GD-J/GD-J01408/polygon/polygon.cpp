#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5*1145],ans;
void dfs(int ma,int l,int r,int sum){
	if(sum>ma){
		ans+=r-l+1;
		ans%=mod;
		return;
	}
	if(l==r)return;
	for(int i=l+1;i<=r;i++){
		dfs(ma,i,r,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		dfs(a[i],0,i-1,0);
	}
	cout << ans;
}

