#include<bits/stdc++.h>
using namespace std;
const int N=5e3+9,mod=998244353;
int n;
int a[N];
bool flag=true;
long long ans,sum;
void dfs(int x,int maxx){
	if (x==n+1){
		if (sum>2*maxx){
			ans++;
			ans%=mod;
		}
		return;
	}
	sum+=a[x];
	dfs(x+1,max(maxx,a[x]));
	sum-=a[x];
	dfs(x+1,maxx);
}
void solve(){
	for (int i=3;i<=n;i++){
		sum=1;
		for (int j=n;j>(n-i);j--){
			sum=(sum*j)%mod;
		}
		for (int j=i;j>=1;j--){
			sum=(sum/j)%mod;
		}
		ans=(ans+sum)%mod;
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	} 	
	if (n>=100){
		solve();
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
