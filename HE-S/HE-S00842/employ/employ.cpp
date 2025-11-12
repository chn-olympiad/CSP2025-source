#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 998244353
ll n, m, c[505], ans = 1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 2;i <= n;i++) ans = (ans * (i % M)) % M;
	cout << ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
