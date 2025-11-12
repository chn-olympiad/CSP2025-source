#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//  freopen("employ.in","r",stdin);
//  freopen("employ.out","w",stdout);
	int n,m,k,a,b,c;
	cin >> n >> m >> k;
	int ans = 0;
	if (k == 0||k == 5||k == 10){
		cout << 0;
	}
	for (int i = 0; i < n;i++){
		cin >> a >> b >> c;
		ans += c;
	}
	cout << ans;
	return 0;
}
