#include <iostream>
#include<string>
#include<algorithm> 
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int n;
vector<int>a;
int ans = 0;
const int mod = 998244353;
void dfs(int c, int _a, int m, long long _sum){
	if(c>=3 && _sum > (m<<1)) {
		ans++;
		ans%=mod;
	}
	//cout<<"c:"<<c<<" _a:"<<_a<<" m:"<<m<<" _sum:"<<_sum<<" ans:"<<ans<<'\n'; 
	for(int i=_a+1;i<=n;i++){
		int _tm = max(a[i],m);
		long long _s = _sum + a[i];
		dfs(c+1,i,_tm,_s);
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a.resize(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n-1;i++){
		dfs(1,i,a[i],a[i]);	
	}
	cout<<ans%mod;
	return 0;
}
