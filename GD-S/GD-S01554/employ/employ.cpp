#include<iostream>
#include<cmath>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define wt(s) (s)=" "+(s)
#define mod 998244353
using namespace std;
const int maxn=100005;
ll n,m,a[maxn],s[maxn],flaga=1,num=0;
string s1;
inline void fre()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
inline void cpy()
{
	for(int i=1;i<=n;i++)
	{
		s[i]=s1[i]-'0';
		if(!s[i]) flaga=0;
	}
}
inline void caseA()
{
	ll ans=1;
	if(n-num<m) 
	{
		cout<<0;
		return;
	}
	for(int i=n-num;i<=n;i++)
	{
		ans=(ans%mod*i%mod)%mod;
	}
	cout<<ans;
} 
int main()
{
	IOS
	fre();
	cin>>n>>m>>s1;
	wt(s1);
	cpy();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!a[i]) num++;
	}
	if(flaga) 
	{
		caseA();
		return 0;
	}
	return 0;
}
