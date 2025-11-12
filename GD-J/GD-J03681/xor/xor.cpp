#include<bits/stdc++.h>
#define i64 long long
using namespace std;
const int maxn=5e5+5;
const int mod=1e9+7;
void solve();
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
int a[maxn];
int ans=0;
void solve(){
	int n,k;
	cin>>n>>k;
	int xr=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xr^=a[i];
		if(xr==k){
			ans++;
			xr=0;
		}
	}
	cout<<ans; 
}

