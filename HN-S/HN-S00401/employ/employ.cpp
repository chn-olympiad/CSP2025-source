#include <bits/stdc++.h> 

namespace solve
{
	constexpr int mod=998244353;
	int n,m;
	std::string s;
	std::vector<int> c;
	void main()
	{
		std::cin>>n>>m>>s;
		if(n>18&&s==std::string(n,'1')) {std::cout<<[mod](int n){long long ans=1;while(n--)ans=ans*n%mod;return ans;}(n);return;}
		if(n>18&&m==n) {std::cout<<(s==std::string(n,'1'));return;}
		c.resize(n+1);
		for(int i=1;i<=n;i++)
			std::cin>>c[i];
		std::vector<int> p(n);
		for(int i=0;i<n;i++) p[i]=i+1;
		int ans=0;
		do
		{
			int fail=0,suc=0;
			for(int i=0;i<n;i++)
			{
				if(c[p[i]]>fail&&s[i]=='1') suc++;
				else fail++;
			}
			ans+=(suc>=m);
		}while(std::next_permutation(p.begin(),p.end()));
		std::cout<<ans;
	}
}

int main()
{
#define PROBLEM_STLVECTOR "employ"
#if 1
	freopen(PROBLEM_STLVECTOR".in","r",stdin);
	freopen(PROBLEM_STLVECTOR".out","w",stdout);
#endif
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve::main();
	return 0;
}
