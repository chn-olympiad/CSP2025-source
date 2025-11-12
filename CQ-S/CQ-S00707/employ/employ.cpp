#include<bits/stdc++.h>
using namespace std;
namespace chole
{
	const int mod=998244353;
	int n,m;
	string s;
	int c[10010];
	int main()
	{
		cin>>n>>m;
		cin>>s;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>c[i];
			if(c[i]!=0)
			{
				cnt++;
			}
		}
		if(m==1)
		{
			long long ans=cnt;
			for(int i=1;i<=n-1;i++)
			{
				ans=1ll*i*ans%mod;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	return chole::main(); 
}
