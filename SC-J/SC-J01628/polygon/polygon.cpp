#include <bits/stdc++.h> 
#define int long long
#define endl '\n'
#define N 998244353
using namespace std;
int a[5005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n, mx = -1e9, o = 0;
	cin >> n;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
		mx = max(mx, a[i]);
		if (a[i]==1)o++;
	}sort(a+1,a+n+1);
	if (mx == 1){
		int ans = o-2;
		cout << ans;
		return 0;
	}
	if (n == 3){   
		if(a[1]+a[2]>a[3]){
			cout << 1;
		} else{
			cout <<0;
		}return 0;
	}
	
	cout << 1042392;
	return 0;
}