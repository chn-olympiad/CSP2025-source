#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define ll long long
using namespace std;
const int M=2e5+5,mod=998244353;
int n,q;
ll ans;
string s1[M],s2[M],s,a;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s1[i]>>s2[i];
	while(q--)
	{
		cin>>s>>a;
		if(s.size()!=a.size())
		{
			puts("0");
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			int x=s.find(s1[i]);
			if(x!=string::npos)ans++;
		}
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}
