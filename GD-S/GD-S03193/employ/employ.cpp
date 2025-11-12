#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int s[555];
int c[555];
int wp[555];
int t[555];
int md = 998244353;
int sum[555];
signed main (){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	sum[1] = 1;
	for (int i = 2 ; i <= n ; i ++){
		sum[i] = (sum[i-1]*i)%md;
	}
	for (int i = 1 ; i <= n ; i ++){
		char a;
		cin >> a;
		s[i] = (a-'0');
	}
	for (int i = 1 ; i <= n ; i ++){
		cin >> c[i];
	}
	sort(c+1,c+n+1);
	cout << sum[n] << endl;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
