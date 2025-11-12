#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
const ll maxn = 5005;
ll n,a[maxn],arr[maxn],cnt = 0,ma,fuc;
bool dis[maxn];
void dfs(ll id,ll z,ll limi){
	if(z>=limi){
		ma = -1;
		fuc = 0;
		for(ll i = 1;i<limi;i++){
			ma = max(ma,a[arr[i]]);
			fuc+=a[arr[i]];
		}
		if(fuc>2*ma) cnt++;
		return;
	}
	for(ll i = id;i<=n;i++){
		if(dis[i]) continue;
		dis[i] = 1;
		arr[z] = i;
		dfs(i,z+1,limi);
		dis[i] = 0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i = 1;i<=n;i++) cin>>a[i];
	for(ll i = 3;i<=n;i++){
		dfs(1,1,i+1);
	}
	cout<<cnt%mod;
	return 0;
} 
