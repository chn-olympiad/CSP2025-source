#include <iostream>
#include <algorithm>
using namespace std;

int a[510],c[510];
const long long mod=998244353;
int n,m,vis[510],g[510];
long long cnt=0;

void dfs(int step,int s,int o)
{
	if(step>n)
	{
		if(s>=m)
		{
			cnt++;
			cnt%=mod;
		}
		return;
	}
	if(m-s>n-step+1)
	{
		return;
	}
	for(int i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			g[step]=i;
			if(o>=c[i] || a[step]==0)
			{
				dfs(step+1,s,o+1);
			}
			else
			{
				dfs(step+1,s+1,o);
			}
			vis[i]=false;
		}
	}
} 

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	int flag=true,flag2=true;
	int cnt1=0;
	string s;
	cin >> s;
	s='#'+s;
	for(int i=1; i<=n; i++)
	{
		a[i]=s[i]-'0';
		if(a[i]!=1)
		{
			flag=false;
		}
		else
		{
			cnt1++;
			if(cnt1>18)
			{
				flag2=false;
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		cin >> c[i];
	}
	sort(c+1,c+n+1);
	if(m==n)
	{
		long long mul=1;
		for(int i=1; i<=n; i++)
		{
			if(a[i]==0 || c[i]==0)
			{
				cout << 0 << endl;
				return 0;
			}
			mul*=i;
			mul%=mod;
		}
		cout << mul << endl;
	}
	else if(m==1)
	{
		if(cnt1==0)
		{
			cout << 0 << endl;
			return 0;
		}
		int k=n+1;
		for(int i=1; i<=n; i++)
		{
			if(a[i]==1)
			{
				k=i;
				break;
			}
		}
		int p=0;
		for(int i=1; i<=n; i++)
		{
			if(c[i]>k-1)
			{
				p=n-i+1;
				break;
			}
		}
		long long mul=p;
		for(int i=n-1; i>=1; i--)
		{
			mul*=i;
			mul%=mod;
		}
		cout << mul << endl;
	}
	else if(cnt1<m)
	{
		cout << 0 << endl;
	}
	else
	{
		dfs(1,0,0);
		cout << cnt << endl;
	}
	return 0;
}
