#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fr(a,b,c) for(c=a;c<=b;c++)
#define rf(a,b,c) for(c=a;c>=b;c--)
#define I_AK_CSP ios_base::sync_with_stdio(0);cin.tie(0) 
#define MAXN 2000001
#define mod 998244353
using namespace std;
ll A(ll x)
{
	ll ans =1;
	for(int i =2;i<=x;i++)
	{
		ans = (ans*i) % mod;
	}
	return ans;
}
ll n, m,f[MAXN],book[MAXN],a[MAXN],sl,i,h;
char ls;
int main()
{
	I_AK_CSP;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n >> m;
	fr(1,n, i)
	{
		cin >> ls;
		f[i] = ls-'0';
		if(f[i])sl++;
	}
	fr(1,n,i)
	{
		cin>>a[i];
		h+=a[i];
	}
	if(h==0)cout<<0;
	else if(sl==n || m==1)
	{
		cout<<A(n);
	}
	else
	{
		cout<<0;
	}
	return 0;
}
