#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int cnt=0;
int Cnx(int x){
	int ans=1;
	for(int i=n; i>=(n-x+1); i--){
		ans*=i;
	}
	for(int i=1; i<=x; i++)
		ans/=i;
	return ans%mod;
}
void dfs(int x, int sum, int maxa){
	if(x==n+1){
		if(sum>2*maxa){
			cnt++;
			cnt%=mod;
			return;
		}
		return;
	}
	dfs(x+1, sum+a[x], max(maxa, a[x]));
	dfs(x+1, sum, maxa);
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1, a+1+n);
	if(n<=30) dfs(1, 0, 0);
	else{
		for(int i=3; i<=n; i++){
			cnt+=Cnx(i);
			cnt%=mod;
			//cout<<Cnx(i)<<' ';
		}
	}
	cout<<cnt<<endl;
	return 0;
}
