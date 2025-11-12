#include <bits/stdc++.h>
#define ll long long
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr)
#define N 502
#define M 998244353

int n,m;
std::string s;
int c[N];
int a[N];
bool vis[N];
int ans = 0;

void dfs(int x){
	if(x == n){
		int tmp = 0;
		int ct = 0;
		for(int i = 1;i <= n;i++){
//			std::cout << a[i] << " " << c[a[i]] << '\n';
			if(ct >= c[a[i]] || s[i - 1] == '0'){
				ct++;
			}else{
				tmp++;
			}
		}
//		std::cout << '\n';
//		std::cout << tmp << '\n';
		if(tmp >= m){
			ans++;
		}
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = true;
			a[x + 1] = i;
			dfs(x + 1);
			vis[i] = false;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	IOS;
	std::cin >> n >> m >> s;
	for(int i = 1;i <= n;i++){
		std::cin >> c[i];
	}
	if(n == m && n > 10){
		for(int i = 1;i <= n;i++){
			if(c[i] == 0){
				std::cout << 0;
				return 0;
			}
		}
		for(int i = 0;i < s.size();i++){
			if(s[i] == '0'){
				std::cout << 0;
				return 0;
			}
		}
		ll ans = 1;
		for(int i = 1;i <= n;i++){
			ans = (ans * i) % M;
		}
		std::cout << ans;
		return 0;
	}
	dfs(0);
	std::cout << ans;
	return 0;
}

