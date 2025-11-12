#include<bits/stdc++.h>
#define pii pair<int,int>
#define allof(o) (o).begin(),(o).end()
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int mod=998244353;
int a[505];
int f[505];
string s;
int n,m;
long long ans;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;s="."+s;
	if(count(allof(s),'1')==n) // 20 pts
	{
		int cnt=count(a+1,a+n+1,0);
		ans=1;
		for(int i=1;i<=n;i++)
			ans=1LL*ans*i%mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	iota(f+1,f+n+1,1);
	do
	{
		int fail_cnt=0,ac_cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(fail_cnt>=a[f[i]])fail_cnt++;
			else if(s[f[i]]=='0')fail_cnt++;
			else ac_cnt++;
		}
		if(ac_cnt>=m)ans++;
	}while(next_permutation(f+1,f+n+1));
	cout<<ans%mod;
	return 0;
}