#include<bits/stdc++.h>
using namespace std;

long long n,m,ans;
char s[509];
int c[509];
bool vis[509];
int a[509];

void dfs(int step)
{
	if(step>n)
	{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1'&&cnt<c[a[i]])
			{
				sum++;
			}
			else
			{
				cnt++;
			}
		}
		
		if(sum>=m)
		{
			ans++;
//			for(int i=1;i<=n;i++)
//			{
//				cout<<a[i]<<' ';
//			}
			//cout<<'\n';
		}
		
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		
		a[step]=i;
		vis[i]=true;
		
		dfs(step+1);
		
		vis[i]=false;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	bool op=true;
	
	cin>>n>>m;
	
	cin>>s+1;
	
	int len=strlen(s+1);
	
	int qq=0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(qq>=c[i])qq++;
		op=op&&s[i]=='1';
	}
	
	if(op==1)
	{
		long long ans=1;
		for(long long i=n-qq;i>=1;i--)
		{
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	
	dfs(1);
	
	cout<<ans%998244353;
	
	return 0;
}
