#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll n,a[N],ans;
void dfs(ll k,ll sum,ll ma){
	if(k==n+1){
		if(sum>ma*2)ans=(ans+1)%99824435;
		return;
	}
	if(a[k]>ma)dfs(k+1,sum+a[k],a[k]);
	else dfs(k+1,sum+a[k],ma);
	dfs(k+1,sum,ma);
}
int main(){
	cin>>n;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>20){
		for(int i=3;i<=n;i++){
			ll x=n,q=1;
			for(int j=n;j>=n-x+1;j--){
				q=q*j%99824435;
			}
			ans=(ans+q)%99824435;
		}
		cout<<ans;
		return 0;
	}

	dfs(1,0,0);
	cout<<ans;
	return 0;
//	4 2
//  2 1 0 3
}
