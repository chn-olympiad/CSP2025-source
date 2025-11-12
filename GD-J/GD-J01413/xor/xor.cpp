#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,k;
ll a[N];
bool fa=true,fb=true;
ll ans;
int main() 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			fa=false;
		}
		if(a[i]!=1 && a[i]!=0)
		{
			fb=false;
		}
	}
	if(fa==true)
	{
		if(k==0)
		{
			cout<<n/2;
		}
		else if(k==1)
		{
			cout<<n;
		}
		return 0;
	}
	else if(fb==true)
	{
		if(k==0)
		{
			ll cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
					cnt=0;
				}
				else
				{
					cnt++;
					if(cnt==2)
					{
						ans++;
						cnt=0;
					}
				}
			}
		}
		else if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
