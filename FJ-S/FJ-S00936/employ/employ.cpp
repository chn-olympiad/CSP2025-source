#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500],b[500],v[500],c[500],ans,f=1,ff=1;
string s;
void dfs(long long x)
{
	if(x==n+1)
	{
		long long y=0;
		for(long long i=1;i<=n;i++)
		{
			if(s[i-1]=='0'||y>=b[a[i]])
			{
				y++;
			}
		}
		if(n-y>=m)ans++;
		ans%=998244353;
	}
	for(long long i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			a[x]=i;
			dfs(x+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++)
	{
		cin>>b[i];
		if(s[i-1]=='0')f=0;
		else if(b[i]==0)ff=0;
	}
	if(n==m)
	{
		if(!ff||!f)cout<<"0";
		else 
		{
			long long res=1;
			for(long long i=1;i<=n;i++)
			{
				res*=i;
				res%=998244353;
			}
			cout<<res;
		}
		return 0;
	}
	dfs(1);
	cout<<ans;
 } 
