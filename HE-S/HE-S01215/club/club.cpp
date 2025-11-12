#include<bits/stdc++.h>
constexpr int man=2e5+10;
int T;
int n;
int s[man];
int f[man][3];
int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	std::cerr.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::cin>>T;
	while(T--) {
		std::cin>>n;
		for(int i=1;i<=n;i++) {
			int a;
			std::cin>>s[i]>>a>>a;
		}
		std::sort(s+1,s+1+n);
		int res=0;
		for(int i=n;i>(n>>1);i--) {
			res+=s[i];
		}
		std::cout<<res<<"\n";
	}
	return 0;
}  
