#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define MAXN 5005
#define MOD 998244353
int n,cnt=0;
int a[MAXN];
bool check(int x)
{
	int i=0,sum=0,maxn=-1,ct=0;
	while(x>0)
	{
		i++;
		if(x&1)
		{
			ct++;
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		x>>=1;
	}
	if(ct>=3&&sum>maxn*2) return 1;
	return 0;
}
signed main()
{
	FAST_IO;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2) {cout<<"0\n";return 0;}
	int maxx=-1;
	for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
	if(maxx==1)
	{
		int ans=1;
		for(int i=1;i<=n;i++) {ans<<=1;ans%=MOD;}
		ans-=n*(n-1)/2+n+1;
		ans=(ans+MOD)%MOD;
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=(1<<n)-1;i++)
	{
		if(check(i)) cnt++,cnt%=MOD;
	}
	cout<<cnt<<'\n';
	return 0;
}
