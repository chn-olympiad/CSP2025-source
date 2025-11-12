#include<bits/stdc++.h>
using namespace std;
bool flat[501],te;
long long n,m,ans,na[501],r[501],t,e;
string tmp;
void dfs(int step,int now)
{
	if(n==(step-e))
	{
		if(now>=m)ans++;
		ans%=998244353;
		return ;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!flat[i])
			{
				flat[i]=true;
				if((step-now)<r[i])
				{
					if(na[step+1]==1)dfs(step+1,now+1);
					else dfs(step+1,now);
				}
				flat[i]=false;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>tmp;
	te=true;
	e=0;
	for(int i=0;i<n;i++)
	{
		na[i+1]=(tmp[i]-'0');
		if(na[i+1]==0)te=false;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	if(m==n&&!te)
	{
		cout<<0<<endl;
	}
	if(m==1)
	{
		ans=0;
		for(int i=m;i<=n;i++)
		{
			t=1;
			for(int j=n;j>=(n-i+1);j--)
			{
				t*=j;
				t%=998244353;
			}
			ans+=t;
			ans%=998244353;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(te)
	{
		ans=0;
		for(int i=m;i<=n;i++)
		{
			t=1;
			for(int j=n;j>=(n-i+1);j--)
			{
				t*=j;
				t%=998244353;
			}
			ans+=t;
			ans%=998244353;
		}
		cout<<ans<<endl;
		return 0;
	}
	memset(flat,0,sizeof(flat));
	ans=0;
	dfs(0,0);
	cout<<ans<<endl;
	return 0;
}
