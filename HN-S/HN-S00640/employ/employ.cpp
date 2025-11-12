#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
constexpr long long N=5e2,M=1e5,V=1e18,mod=998244353;
long long n,m;
bitset<N+5> s;
int c[N+5];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	m=n-m;
	for(int i=1;i<=n;i++)
	{
		char x;cin>>x;
		s[i]=x-'0';
	}
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		c[i]=x;
	}
	if(n<=10)
	{
		long long ans=0;
		vector<int> vc;
		for(int i=1;i<=n;i++) vc.push_back(i);
		do
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				bool f=(!s[i])||(sum>=c[vc[i-1]]);
				if(f) sum++;	
			}
			if(sum<=m) ans++;
		}
		while(next_permutation(vc.begin(),vc.end()));
		cout<<ans%mod;
	}
	return 0;
}
//next_permutation
//I want to be on the confused behaviors in CSP-S of HuNan.
//And meet some new friend through this way.
//But I forget my luogu uid QwQ.
//
//
//
