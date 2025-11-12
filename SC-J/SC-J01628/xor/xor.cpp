#include <bits/stdc++.h> 
#define int long long
#define endl '\n'
using namespace std;
int a[500005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n, k,cnt = 0;
	cin >> n >> k;
	for (int i = 1;i <= n;i ++)cin >> a[i];
	for (int i = 1;i <= n;i ++){
		if (a[i]==k||a[i-1]==a[i])cnt ++;
	}
	
	cout << cnt;
	
	return 0;
}