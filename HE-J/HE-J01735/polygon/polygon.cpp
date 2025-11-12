#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n;
int a[5100];
int ma = - 1,cnt;
int ans,sum;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		sum += a[i];
		ma = max(ma,a[i]);
		if(a[i] == 1)cnt ++; 
	}
	if(n == 1 || n == 2){
		cout << 0;
		return 0;
	}
	if(n == 3){
		if(sum > ma * 2){
			ans = 1;
		}else ans = 0;
	}else
	if(cnt == n)ans = n * (n - 1) / 2 - n + 1;
	cout << ans;
	return 0;
}


