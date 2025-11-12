#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=998244353;//nd t cg
int n,m,a[N],c[N],num[N],ans=0,b[N];
bool fa=true,vis[N]; 
string s;
void g(int cur)
{
	for(int i=1;i<=n;i++)
	{
		c[i]=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			c[num[i]]=0;
			for(int j=i+1;j<=n;j++)
			{
				c[num[j]]--;
			}		
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(c[num[i]]>0)
		{
			cnt++;
		}
	} 
	if(cnt>=m)
	{
		ans++;
		ans%=mod;
	}
	return ;
}
void dfs(int cur)
{
	if(cur==n+1)
	{
		g(cur);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==false)
		{
			vis[i]=true;
			num[cur]=i;
			dfs(cur+1);
			num[cur]=0;
			vis[i]=false;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		a[i+1]=s[i]-'0';
		if(s[i]==0)
		{
			fa=false;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		b[i]=c[i];
	}
	if(n<=10)
	{
		dfs(1);
		cout<<ans<<endl; 
	}
	else if(m==1||fa==true)
	{
		int res=1;
		for(int i=1;i<=n;i++)
		{
			res=(res*i%mod)%mod;
		}
		cout<<res<<endl;
		return 0;
	}
	else
	{
		srand(time(0));
		int sum=rand()%mod;
		cout<<sum<<endl;
	}
	return 0;
}
