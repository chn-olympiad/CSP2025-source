#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,mod=998244353;
string s;
int f[N],c[N],t[N],ans[N];
int n,m,cnt;
long long sum;
void dfs(int x)
{
	if(x==n+1)
	{
		int num=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='1'&&c[ans[i]]>f[i])
			{
				num++;
				if(num>=m)break;
			}
		}
		if(num>=m)
		{
			sum++;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!t[i])
		{
			ans[x]=i;
			t[i]=1;
			dfs(x+1);
			t[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')cnt++;
		f[i+1]=cnt;
	}
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]!=0)cnt++;
	}
	if(f[n]==0)
	{
		sum=1;
		for(int i=1;i<=m;i++)
		{
			sum*=cnt;
			cnt--;
			sum%=mod;
		}
		cout<<sum%mod;
		return 0;
	}
	dfs(1);
	cout<<sum;
	return 0;
}
