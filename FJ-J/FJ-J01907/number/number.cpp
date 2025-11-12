#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10;
int ans;
int a[N];
int len = 0;
std::string s;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin>>s;
	for (int i = 0;i <= s.size()-1;i++){
		if ('0' <= s[i] && s[i] <= '9') {
			a[++len] = s[i] - '0';
		}
	}
	std::sort(a + 1, a + len + 1);
	for (int i = len;i >= 1;i--){
		printf("%ld",a[i]);
	}
	return 0;
}
