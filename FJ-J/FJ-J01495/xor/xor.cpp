#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++)cin >> a[i];
	if(k==0)cout << 0;
	cout << n/k;
	 
	return 0;
}
