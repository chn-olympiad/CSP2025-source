#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod=998244353;
string s;
int arr[101];
int n,m;
ll ans;
bool vis[101];
int p[101];
bool check()
{
	ll cnt=0;
	ll res=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0'||cnt>=arr[p[i]])
		{
			cnt++;
	    }
	    else
	    res++;
    }
    return res>=m;
}
void f(int i)
{
	if(i==n)
	{
		if(check())
		ans=(ans+1)%mod;
	}
	for(int j=0;j<n;j++)
	{
		if(!vis[j])
		{
			vis[j]=true;
			p[i]=j;
			f(i+1);
			vis[j]=false;
			p[i]=j;
	    }
    }
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	if(m==n)
	{
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0'||arr[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
    }
	f(0);
	cout<<ans;
	return 0;
}
