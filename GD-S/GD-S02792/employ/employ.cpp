#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long n,m,c[100010],ans,t,w1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1 ;i <= n ;i++)
		cin >> c[i];
	for(int i = m;i <= n ; i++){
		w1 = n;
		t = 1;
		for(int j = 1;j <= i ;j++){
			t *= w1;
			w1--;
			t %= MOD;
		}
		ans += t;
		ans	%=MOD
	}
	cout << ans;
}
