#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mo=998244353;
ll n,m,c[505],s,a[505];
string ss;
bool f=0,ff[505];
void dfs(ll k)
{
	if(k==n+1)
	{
		ll t=0,z=0;
		for(int i=1;i<=n;i++)
		{
			if(t>=a[i] || ss[i-1]=='0') t++;
			else z++;
		}
		if(z>=m)
		{
			s++;
			s%=mo;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!ff[i])
		{
			ff[i]=1;
			a[k]=c[i];
			dfs(k+1);
			ff[i]=0;
			a[k]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m;
	cin >> ss;
	for(int i=0;i<ss.size();i++) if(ss[i]=='0') f=1;
	for(int i=1;i<=n;i++) cin >> c[i];
	if(!f)
	{
		ll a=1;
		for(int i=n;i>=2;i--) a=a*i%mo;
		cout << a;
		return 0;
	}
	else if(m==n)
	{
		cout << 0;
		return 0;
	}
	dfs(1);
	cout << s;

	return 0;
}
/*
Rp++ 
T4ÍÇ·ÏÁË 
³õ²â£º
T1 »Æ~ÂÌ
T2 ÂÌ~À¶-
T3 À¶-~×Ï-
T4 ÂÌ+~À¶+
*/
