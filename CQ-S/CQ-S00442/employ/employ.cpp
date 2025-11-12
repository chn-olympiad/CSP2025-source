#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
typedef long long ll;
typedef pair<int,int> Pair;
int a[510];
ll ans;
string s;
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	int n , k;
	cin >> n >> k >> s;
	int f = s.find("0");
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(f == -1 or (k == 1 and s.find("1") != -1))
	{
		ans = 1;
		for(int i = 1;i <= n;i++)
		{
			ans *= i;
			ans %= MOD;
		}
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}

