#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5010];
int n;
int ans=0;
void dfs(int sum,int num,int i,int last){
	if(i>n){
		if(num<3) return;
		if(sum<=2*last) return;
		ans=(ans+1)%998244353;
		return;
	}
	dfs(sum,num,i+1,last);
	dfs(sum+a[i],num+1,i+1,a[i]);
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		int anse=1;
		for(int i = 1;i<=n;i++){
			anse=(anse*2)%998244353;
		}
		anse=((anse-n*(n-1)/2-n-1)%998244353+998244353)%998244353;
		cout << anse;
		return 0;
	}
	dfs(0,0,1,0);
	cout << ans;
	return 0;
}