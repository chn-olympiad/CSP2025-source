//GZ-S00368 华东师范大学附属贵阳学校 罗翊航
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll n , m , c[505] , s[505] , cnt;
string s1;
bool flag = 1;
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m;
	cin >> s1;
	for(int i = 0; i < n; i++){
		s[i] = s1[i] - '0';
	}
	for(int i = 0; i < n; i++){
		cin >> c[i];
		if(c[i] == 0)cnt++;
	}
	n-=cnt;
	ll ans1 = 1;
		for(int i = n - m + 1; i <= n; i++){
			ans1 *= i;
			ans1 %= MOD;
		}
		cout << ans1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

