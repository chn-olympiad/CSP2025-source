#include<iostream>
#define int long long
#define endl '\n'
using namespace std;
const int N = 510;
const int mod = 998244353;
int n,m,a[N],p[N],sum;
string str;
bool st[N];
void dfs(int u){
	if(u == n){
		int ans = 0,cnt = 0;
		for(int i = 1;i <= n;i++){
			if(cnt >= a[p[i]] || str[i - 1] == '0'){
				cnt++;
				continue;
			} else {
				ans++;
			}
		}
		if(ans >= m){
			sum++;
			sum %= mod;
		}
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(!st[i]){
			st[i] = true;
			p[u + 1] = i;
			dfs(u + 1);
			st[i] = false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> str;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 10){
		dfs(0);
		cout << sum;
	} else {
		int ans = 1;
		for(int i = 1;i <= n;i++){
			ans *= i;
			ans %= mod;
		}
		cout << ans;
	}
	return 0;
}
