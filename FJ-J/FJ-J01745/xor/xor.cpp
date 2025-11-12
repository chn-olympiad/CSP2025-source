#include <bits/stdc++.h>
#include <map>
#define N 500005

int n;
int k;
int a[N];
int s[N];
int dp[N];
int mx[N];
std::map< int, int > las;
int ans;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> k;
	for(int i = 1;i <= n;i++){
		std::cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
//	for(int i = 1;i <= n;i++){
//		std::cout << s[i] << " ";
//	}
//	std::cout << '\n';
	las[0] = 0;
	for(int i = 1;i <= n;i++){
		las[s[i]] = i;
		if(las.find(s[i] ^ k) != las.end()){
			dp[i] = mx[las[s[i] ^ k]] + 1;
		}
		mx[i] = std::max(dp[i],mx[i - 1]);
	}
	std::cout << mx[n];
	return 0;
}

