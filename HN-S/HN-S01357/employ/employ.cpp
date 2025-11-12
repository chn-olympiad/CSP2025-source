#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
using ll=long long;
#define File_IO 1
#define debug 0
void Ex_gcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		//1a+0=gcd(a,0)
		return;
	}
	Ex_gcd(b,a%b,y,x);
	y-=std::floor(a/b)*x;
	//b(x1)+(a-floor(a/b)*b)(y1)=gcd(a,b)
	//a(y1)+b(x1-floor(a/b)*y1)=gcd(a,b)
}
const int maxn=501;
const ll modp=998244353;
ll ex_gcd_inv(ll a)
{
	ll x,y;
	Ex_gcd(a,modp,x,y);
	return x;
}
struct con_calc
{
	vector<ll> peng;
	void init(int n=0)
	{
		peng.resize(n+1);
		peng[0]=1;
		for(int i=1;i<=n;i++)(peng[i]=peng[i-1]*i)%=modp;
	}
	ll operator()(ll n,ll m)const
	{
		return peng[n]*ex_gcd_inv(peng[n-m]*peng[m]%modp)%modp;
	}
}cc;
int qpow(int base,unsigned power)
{
	int wer=1;
	while(power)
	{
		if(power&1)(wer*=base);
		power>>=1;
		(base*=base)%=modp;
	}
	return wer;
}
int n,m,c[maxn];
string s;
int main()
{
	#if File_IO
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	#endif
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	cout<<qpow(2,n);
	return 0;
}
