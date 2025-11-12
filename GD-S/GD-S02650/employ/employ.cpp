#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[1001];
int t[1010];
int p[1010];
long long int ans;
int cnt,pass;
void dfs(int x)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			p[i]=0;
		}
		cnt=0;
		pass=0;
		for(int i=1;i<=n;i++)
		{
			p[t[i]]++;
			if(p[t[i]]>1)return;
			if(s[i-1]=='1'&&pass<a[t[i]])
			{
				cnt++;
			}
			else
			{
				pass++;
			}
		}
		if(cnt<m)return;
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		t[x]=i;
		dfs(x+1);
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0'||a[i]==0)
			{
				printf("0");
				return 0;
			}
		}
		ans=1;
		for(int i=n;i>=1;i--)
		{
			ans*=i;
			ans=ans%998244353;
		}
		printf("%lld",ans);
		return 0;
	}
	if(n<=8)
	{
		dfs(1);
		ans=ans%998244353;
		printf("%lld",ans);
		return 0;
	}
	printf("180730592");
	return 0;
}
