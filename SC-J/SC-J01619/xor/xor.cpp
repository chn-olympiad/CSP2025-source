#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
set<int> vis;
int pre[N];
int ans;
signed main(){
#ifndef DEBUG
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#endif
//	freopen("xor\\xor6.in","r",stdin);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	vis.insert(0);
	for (int i=1;i<=n;i++){
		pre[i]=pre[i-1]^a[i];
		if (vis.count(pre[i]^k)){
			ans++;
			vis.clear();
		}
		vis.insert(pre[i]);
	}
	cout<<ans<<"\n";
}