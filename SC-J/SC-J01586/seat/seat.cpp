#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m,Rs,cnt = 1,ans1,ans2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> Rs;
	for(int i = 2;i <= n*m;i++){
		int num;
		cin >> num;
		if(num > Rs) cnt++;
	}
	if(cnt % n == 0) ans1 = cnt / n;
	else ans1 = cnt / n + 1;
	if(ans1 % 2 == 1) ans2 = (cnt % n == 0 ? n : cnt % n);
	else ans2 = n - cnt % n + 1;
	cout << ans1 << " " << ans2;
	return 0;
}