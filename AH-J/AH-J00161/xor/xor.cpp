#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
void solvea(int n,int k)
{
	if(k!=1&&k!=0)
	{cout<<0;return;}
	int ans;
	if(n%2)
	{
		if(k)
		{
			ans=(n+1)*((n-1)/2+1)/2;
		}
		else
		{
			ans=(n+1)*((n-3)/2+1)/2;
		}
	}
	else
	{
		if(k)
		{
			ans=(n+2)*((n-2)/2+1)/2;
		}
		else
		{
			ans=n*((n-2)/2+1)/2;
		}
	}
	cout<<ans;
	return;
}
void solveb(int n,int k)
{
	if(k!=1&&k!=0)
	{cout<<0;return;}
	int ans;
	if(n%2)
	{
		if(k)
		{
			ans=(n+1)*((n-1)/2+1)/2;
		}
		else
		{
			ans=(n+1)*((n-3)/2+1)/2;
		}
	}
	else
	{
		if(k)
		{
			ans=(n+2)*((n-2)/2+1)/2;
		}
		else
		{
			ans=n*((n-2)/2+1)/2;
		}
	}
	cout<<ans;
	return;
}
void solve(int n,int k)
{
	int ans;
	if(n%2)
	{
		if(k)
		{
			ans=(n+1)*((n-1)/2+1)/2;
		}
		else
		{
			ans=(n+1)*((n-3)/2+1)/2;
		}
	}
	else
	{
		if(k)
		{
			ans=(n+2)*((n-2)/2+1)/2;
		}
		else
		{
			ans=n*((n-2)/2+1)/2;
		}
	}
	cout<<ans;
	return;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int>x(n+5);
	for(int i=1;i<=n;i++)
		cin>>x[i];
	bool a=1,b=1;
	for(int i=1;i<=n;i++)
	{
		if(x[i]!=1&&x[i]!=0)
			a=0,b=0;
		else
			if(x[i]==0)
			{
				a=0;
			}
	}
	if(a&&b) solvea(n,k);
	else if(!a&&b) solveb(n,k);
	else solve(n,k); 
	cout<<endl;
	return 0;
}
