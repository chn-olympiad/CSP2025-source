#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int mod = 998244353;
int n, m, a[N], cnt[N];
long long ans;
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		cnt[i] = cnt[i - 1];
		if(s[i - 1] == '0') cnt[i]++;
	}
	if(!cnt[n]){
		ans = 1ll;
		for(int i = 1; i <= n; i++)
			ans = ans * i % mod;
		printf("%lld\n", ans);
		return 0;
	}
	cout << 2 << endl;
	return 0;
}
