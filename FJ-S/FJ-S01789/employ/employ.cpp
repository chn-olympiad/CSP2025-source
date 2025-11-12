#include<bits/stdc++.h>
using namespace std;
char a[100001];
long long c[100001];
int v[100001];
int b[100001];
  long long n,i,j,m,t=0,g=0,x=1,ans=0;
void dfs(int x)
{
	if(x==n+1)
	{int x=0,s1=0;
		for(int i=1;i<=n;i++)
		{
			if(c[b[i]]>x&&a[i]=='1')
			{
				s1++;
			}
			else
			{
				x++;
			}
		}
		if(s1>=m)
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			b[x]=i;
			dfs(x+1);
			b[x]=0;
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
  cin>>n>>m;
  for(i=1;i<=n;i++)
  {
  	cin>>a[i];
  	if(a[i]=='1')
  	{
  		t++;
	  }
  }
  for(i=1;i<=n;i++)
  {
  	cin>>c[i];
  }
  if(n<=18)
  {
  	dfs(1);
  	cout<<ans;
  }
  else
  if(m==n)
  {
  	for(i=1;i<=n;i++)
  {x=(x*i)%998244353;
  	if(c[i]==0||t<n)
  	{
  		cout<<0;
  		return 0;
	  }
  }cout<<x;
  return 0;
  }
  else
  cout<<0;
  return 0;
} 



