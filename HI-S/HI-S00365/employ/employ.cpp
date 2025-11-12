#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998224353;
int a[505];
string s;
int n,m,ans=0;
void dfs(int x)
{
	if(x==1)
	{
		if(s[0]=='1') ans++;
		ans%=mod;
	}
	else if(x==2)
	{
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				int b[15]={a[i],a[j]};
				int o=0,num=0;
				for(int k=0;k<n;k++)
				{
					if(o>=b[k]) continue;
					if(s[k]=='1') num++;
					else o++;
				}
				if(num>=m) ans++,ans%=mod;
			}
		}
	}
	else if(x==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int p=1;p<=n;p++)
				{
					if(i==j||i==p||j==p) continue;
					int b[15]={a[i],a[j],a[p]};
					int o=0,num=0;
					for(int k=0;k<n;k++)
					{
						if(o>=b[k]) continue;
						if(s[k]=='1') num++;
						else o++;
					}
				if(num>=m) ans++,ans%=mod;
			}
			}
		}
	}
	else if(x==4){
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int p=1;p<=n;p++)
				for(int u=1;u<=n;u++)
				{
				if(i==j||i==p||j==p||i==u||j==u||p==u) continue;
				int b[15]={a[i],a[j],a[p],a[u]};
				int o=0,num=0;
				for(int k=0;k<n;k++)
				{
					if(o>=b[k]) continue;
					if(s[k]=='1') num++;
					else o++;
				}
				if(num>=m) ans++,ans%=mod;
			}
			}
		}
	}
	else if(x==5)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int p=1;p<=n;p++)
				for(int u=1;u<=n;u++)
				{
					for(int r=1;r<=n;r++)
					{
				if(i==j||i==p||j==p||i==u||j==u||p==u||r==i||r==j||r==p||r==u) continue;
				int b[15]={a[i],a[j],a[p],a[u],a[r]};
				int o=0,num=0;
				for(int k=0;k<n;k++)
				{
					if(o>=b[k]) continue;
					if(s[k]=='1') num++;
					else o++;
				}
				if(num>=m) ans++,ans%=mod;
			}
			}
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=5)
	{
		dfs(n);
		cout<<ans;
		return 0;
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1') ans++;
	}
	if(ans==s.size())
	{
		ll num=1;
		for(int i=1;i<=n;i++)
		{
			num*=i;
			num%=mod;
		}
		cout<<num;
		return 0;
	}
	if(m>ans||m>18) {
	cout<<0;
	return 0;
}
	return 0;
}

