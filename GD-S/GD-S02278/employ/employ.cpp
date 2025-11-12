#include<iostream>
using namespace std;
long long n,m,a[505],b[505],c[505],ans=0;
void dfs(int x,int y,int z)
{
//	cout<<x<<" "<<y<<" "<<z<<endl;
	if(x==m)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==1)
		{
			continue;
		}
		if(z>=b[i])
		{
			c[i]=1;
			dfs(x,y+1,z+1);
			c[i]=0;
		}
		else
		{
			if(a[y]==0)
			{
				c[i]=1;
				dfs(x,y+1,z+1);
				c[i]=0;
			}
			else
			{
				c[i]=1;
				dfs(x+1,y+1,z);
				c[i]=0;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	int l;
	cin>>n>>m;
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++)
	{
		a[i+1]=int(s[i]-'0');
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(n==m)
	{
		cout<<1<<endl;
		return 0;
	}
	dfs(0,1,0);
	cout<<ans<<endl;
	return 0;
}
