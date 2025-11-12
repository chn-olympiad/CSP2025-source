#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll n;
ll a[N];
ll ans;
bool f=true;
bool vis[N];
vector<ll> q;
void fun(int x,int b)
{
	if(q.size()>=3)
	{
		ll maxx=0,h=0;
		for(int i=0;i<q.size();i++)
		{
			h+=q[i];
			maxx=max(maxx,q[i]);
		}
		if(h>maxx*2)
		{
			ans++;
		}
	}
	for(int i=b;i<=n;i++)
	{
		
		if(!vis[i])
		{
			vis[i]=true;
			q.push_back(a[i]);
			fun(x-1,i+1);
			vis[i]=false;
			q.pop_back();
		}
	}
}
int main() 
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	if(n<3)
	{
		int a,b;
		cin>>a>>b;
		cout<<0;
		return 0;
	}
	else if(n==3)
	{
		int a,b,c;
		cin>>a>>b>>c;
		ll cnt=a+b+c;
		ll maxx=max(max(a,b),c);
		if(cnt>2*maxx)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			f=false;
		}
	}
	if(f)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=n-(i-1);
			if(ans>=998244353)
			{
				ans%=998244353;
			}
		}
		cout<<ans;
		return 0;
	}
	fun(n,1);
	cout<<ans%998244353; 
	return 0;
}
