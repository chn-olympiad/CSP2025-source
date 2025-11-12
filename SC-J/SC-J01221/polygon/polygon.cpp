//普巴保佑我AC
#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N=20;
const int mod=998244353;
int n,ans;
int d[5005];
int q[1<<N];
int mx[1<<N];
inline bool check(int x)
{
	int s=0;
	while(x)
	{
		s+=(x&1);
		if(s>=3)
			return 1;
		x>>=1;
	}
	return 0;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>d[i];
	map<int,bool> mp;
	for(int c=0;c<(1<<n);++c)
	{
		for(int j=1;j<=n;++j)
		{
			if(c&(1<<(j-1))) continue;
			int nc=c|(1<<(j-1));
			mx[nc]=max(mx[c],d[j]);
			q[nc]=q[c]+d[j];
			if(!check(nc)) continue;
			if(q[nc]>2*mx[nc])
			{
				if(mp.count(nc)==0)
				{
					ans=(ans+1)%mod;
					mp[nc]=1;
//					cout<<nc<<endl;	
				}
			}	
		}
	}
	cout<<ans;
	return 0;
}