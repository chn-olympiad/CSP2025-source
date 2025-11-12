#include<bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
ll n,c[505],m,nf0,ans,turn[505];
string s;
bool A=true,vis[505];
void sloveA()
{
	int ans=n-nf0>0?1:0;
	for(int i=1;i<=n-nf0;i++)
	{
		ans*=i;
		ans%=MOD;
	}
	cout<<ans;
}
bool check()
{
	ll nf=0,np=0;
	for(int i=1;i<=n;i++)
	{
		if(nf<c[turn[i]])
		{
			if(s[i-1]=='0') nf++;
			else np++; 
		}
		else
		{
			nf++;
		}
	}
	return np>=m;
}
void dfs(int step)
{
	if(step>n)
	{
		if(check())
		{
			ans+=1;
			ans%=MOD;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			turn[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) 
	{
		if(s[i]=='0') A=false;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0) nf0++;
	}
	if(m==n)
	{
		if(A) cout<<1;
		else cout<<0;
		return 0;
	}
	else if(A)
	{
		sloveA();
		return 0;
	}
	else 
	{
		dfs(1);
		cout<<ans;
	}
	return 0;
}


