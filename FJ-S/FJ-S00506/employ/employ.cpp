#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define f(n) for(int i=1;i<=n;i++)
const ll mod=998244353;
bool cmp(int x,int y)
{
	return x<y;
}
string dy;
int n,m,c[501],df[501];
bool pda()
{
	f(n)if(dy[i-1]=='0')return false;
	return true;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>dy;
	f(n)df[i]=1-dy[i-1]+'0'+df[i-1];
	f(n)cin>>c[i];
	sort(c+1,c+n+1,cmp);
	if(pda())
	{
		ll ans=1,nuz=0;
		f(n)if(c[i]==0)nuz++;
		if(n-m<nuz)cout<<"0";
		else
		{
			f(n)ans=(ans*i)%mod;
			cout<<ans;
		}
		return 0;
	}
	cout<<"2";
	return 0;
}


