#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int inf=0x3f3f3f3f;
const ll INF=1e16;
const int N=510;
int c[N];
ll A(ll n,ll m)
{
	ll ans=1;
	for(ll i=n;i>=(n-m+1);i--)
	{
		ans*=i;
		ans=ans%998244353;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	bool fa=1,ff=1;
	for(auto it :s)
	{
		if(it!='1') fa=0;
		if(it!='0') ff=0;
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0) cnt++;
	}
//	cout<<A(5,5);
	if(cnt==n)
	{
		if(ff) cout<<A(n,n);
		else cout<<"0"<<endl;
		return 0;
	}
	if(m==1)
	{
		if(s[1]=='0') 
		{
			cout<<A(n,n);
			return 0;
		}
		ll x=A(n-1,n-1);
		cout<<((n-cnt)*x)%998244353;
		return 0;
	}
	if(m==n)
	{
		int tmp=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='1') tmp++;
			if(c[i+1]<tmp)
			{
				cout<<"0"<<endl;
			}
		}
		cout<<A(n,n)<<endl;
		return 0;
	}
	if(fa)
	{
		sort(c+1,c+n+1);
		ll x=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]>x)
			{
				ans*=(c[i]-x);
				ans=ans%998244353;
				x++;
				
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}

