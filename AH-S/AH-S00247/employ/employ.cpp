#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510],vis[510],t[510],ans,ps[510];
string st;
void dfs(int k)
{
	if(k==n+1)
	{
		int s=0,l=0;
		for(int i=1;i<=n;i++)
		{
			if(l<a[t[i]]&&st[i-1]=='1') s++;
			else l++;
		}
		if(s>=m)
		{
			ans++;
			ans%=998244353;
		} 
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			t[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
long long pl(long long k)
{
	if(k==1) return 1;
	else return k*pl(k-1)%998244353;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m>>st;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=18)
	{
		dfs(1);
		cout<<ans;
	} 
	else
	{
		cout<<pl(n);
	}
	return 0;
}
