#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
const int N = 1e4+50;
const int mod = 998244353;
using namespace std;
ll n,a[N],ma,cn;
bool vis[N];
void dfs(ll x,ll sum,ll m,ll num){
	if(num>=3){
		if(sum>m*2){
			cn++;
			cn%=mod;
		}
	}
	for(int i=x;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i+1,sum+a[i],max(m,a[i]),num+1);
			vis[i]=0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		ma=max(ma,a[i]);
	}
//	if(ma==1){
//		ll ans=0;
//		for(int j=3;j<=n;j++){
//			ans+=(j-1)*(j/2);
//			ans%=mod;
//		}
//		cout <<ans <<endl;
//		return 0;
//	}
	dfs(1,0,0,0);
	cout <<cn <<endl;
	return 0;
}




