#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i(a);i<=(b);++i)
#define req(i,a,b) for(int i(a);i>=(b);--i)
// #define sort stable_sort
using namespace std;
constexpr int mod=998244353;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n,m; cin>>n>>m;
	string s; cin>>s;
	vector<int> c(n); for(auto &x:c) cin>>x;
	if(n==m)
	{
		if(any_of(c.begin(),c.end(),[&](int x){return !x;})) puts("0");
		else if(count(s.begin(),s.end(),'1')!=n) puts("0");
		else
		{
			int fac=1;
			rep(i,1,n) fac=fac*i%mod;
			cout<<fac<<'\n';
		}
		exit(0);
	}
	if(n<=10)
	{
		vector<int> p(n); iota(p.begin(),p.end(),0);
		int ans=0;
		do
		{
			int quit=0,ok=0;
			rep(idx,0,n-1)
			{
				int i=p[idx];
				if(quit>=c[i]) {++quit;continue;}
				if(s[idx]=='0') {++quit;continue;}
				++ok;
			}
			ans+=ok>=m;
		} while(next_permutation(p.begin(),p.end()));
		cout<<ans<<endl;
	}
	return 0;
}
