#include<bits/stdc++.h>
using namespace std;
const long long MI=998244353;
int pa[505];
bool f[505];
long long ans=0;
int n,m;
string s;
void dfs(int i,int di)
{
	if(i>n)
	{
		ans++;
	}
	if(m-di>n-i)
	{
		return;
	}
	for(int j=1;j<=n;j++)
	{
		if(f[j])
		{
			continue;
		}
		f[j]=true;
		int u=0,v=0;
		if(s[0]=='0')
		{
			u=1;
		}
		else if(di>=pa[j])
		{
			v=1;
		}
		dfs(i+1,di+max(u,v));
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	bool f=true;
	int r=0,u=0;
	for(int i=1;i<=n;i++)
	{
		cin>>pa[i];
		if(pa[i]==0)
		{
			r++;
		}
	}
	sort(pa+1,pa+1+n);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			f=false;
			u++;
		}
	}
	if(r>n-m||u>n-m)
	{
		cout<<0;
	}
	else if(m==1)
	{
		long long sum=1;
		for(long long i=(long long)n-1;i>1;i--)
		{
			sum*=i;
			sum%=MI;
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				for(int j=1;j<=n;j++)
				{
					if(pa[j]>=i+1)
					{
						sum*=(long long)(n-j+1);
						sum%=MI;
						cout<<sum;
						return 0;
					}
				}
				cout<<0;
				break;
			}
		}
	}
	else if(f==true)
	{
		long long sum=1;
		for(long long i=(long long)n;i>1;i--)
		{
			sum*=i;
			sum%=MI;
		}
		cout<<sum;
	}
	else if(n<=10)
	{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}
