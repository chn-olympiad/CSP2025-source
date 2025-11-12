#include<iostream>
#include<cmath>
#include<algorithm>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 998244353
using namespace std;
const int maxn=5005;
ll n,a[maxn],max1=0,ans=0,b[maxn],cnt=0,c[maxn][maxn];
inline void fre()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
}
inline void ceshi(ll m)
{
	cnt=0;
	while(m)
	{
		ll c=m%2;
		m/=2;
		b[++cnt]=c;
	}
	for(int i=cnt;i>=1;i--) cout<<b[i];
	cout<<endl;
}
inline void caseA()
{
	ll ans=0;
	for(int i=0;i<=n;i++) c[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[i][j]=(c[i-1][j]%mod+c[i-1][j-1]%mod)%mod;
		}
	}
	for(int i=3;i<=n;i++)
	{
		ans=(ans%mod+c[n][i]%mod)%mod;
	}
	cout<<ans;
}
int main()
{
	IOS
	fre();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		max1=max(max1,a[i]);
	}
	if(max1<=1) 
	{
		caseA();
		return 0;
	}
	for(int i=0;i<=(1<<n)-1;i++)
	{
		ll x=__builtin_popcount(i),sum=0,maxx=0,cnt=0;
		if(x<3) continue;
		for(int j=0;j<=n-1;j++)
		{
			if(i&(1<<j)) 
			{
				sum+=a[n-j];
				maxx=max(maxx,a[n-j]);
			}
		}
		if(sum>2*maxx) 
		{
			ans=(ans%mod+1)%mod;
			//ceshi(i);
		}
	}
	cout<<ans%mod;
	return 0;
} 
