#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 998244353;
int a[5005];
ll ans = 0;
int n;
void dfs(int s,int si,int l,ll sum,int mx){
	//cout <<sum << " " <<  s << " " << si <<  endl;
	for(int i = s;i <= n - l + si;i++){
		sum += a[i];
		if(si < l){
			dfs(i + 1,si + 1,l,sum,max(mx,a[i]));
		}
		int mm = mx;
		mx = max(mx,a[i]);
		if(si == l && sum > mx * 2){
			//cout << " " << sum << " " << mx << " " << l << " " << endl;
			ans++;
			ans %= MOD;
		}
		mx = mm;
		sum -= a[i];
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 3;i <= n;i++){
		dfs(1,1,i,0,-1);
		//cout << endl;
	}
	cout << ans;
}
