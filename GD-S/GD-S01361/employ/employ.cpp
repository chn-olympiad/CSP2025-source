#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
const int mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(0);
	int n,m;
	std::cin>>n>>m;
	std::string s;
	std::cin>>s;
	std::vector<int> c(n);
	std::vector<long long> f(n+1);
	for(int i=0;i<n;i++) std::cin>>c[i];
	long long ans=0;
	f[0]=0;
	f[1]=1;
	for(int i=2;i<=n;i++) f[i]=std::max(f[i-1]*i,f[i-1]);
	std::sort(c.begin(),c.end());
	//std::cout<<f[n];
	for(long long i=1;i<=f[n];i++){
		int out=0;
		int ok=0;
		for(int j=0;j<s.size();j++){
			if(s[j]=='0'||out>=c[j]) out++;
			else ok++;
		}
		if(ok>=m) ans++;
		std::next_permutation(c.begin(),c.end());
		//for(int i=0;i<c.size();i++) std::cout<<c[i];
		//std::cout<<'\n';
	}
	std::cout<<ans%mod;
	return 0;
}
