#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll a[N],sum[N];
void solve(){
	ll n,k;
	cin >> n >> k;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum[i]=sum[i-1]^a[i];
	}
	ll pre=1;
	map<ll,ll> mp;
	mp[0]=0;
	for(int i=1;i<=n;i++){
//		for(int j=pre;j<=i;j++){
//			if((sum[i]^k)==sum[j-1]){
//				pre=i+1;
//				ans++;
////				cout << i << " " << j << "\n";
//				break ;
//			}
//		}
		if(mp[(sum[i]^k)]==0&&(sum[i]^k)!=0){
			mp[sum[i]]=i;
			continue ;
		}
		ll id=mp[(sum[i]^k)]+1;
		if(id>=pre&&id<=i){
			pre=i+1;
			ans++;
		}
		mp[sum[i]]=i;
	}
	cout << ans << "\n"; 
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

