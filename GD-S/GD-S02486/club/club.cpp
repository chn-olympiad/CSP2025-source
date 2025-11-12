#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],b[N],c[N],ans;
void dfs(int u,int x,int y,int z,int sum)
{
	if(u>n)
	{
		if(x<=n/2&&y<=n/2&&z<=n/2)
		{
			ans=max(ans,sum);
		}
		return;
	}
	if((x+1)<=n/2)
	{
		dfs(u+1,x+1,y,z,sum+a[u]);
	}
	if((y+1)<=n/2)
	{
		dfs(u+1,x,y+1,z,sum+b[u]);
	}
	if((z+1)<=n/2)
	{
		dfs(u+1,x,y,z+1,sum+c[u]);
	}
}
void solve1()
{
	dfs(1,0,0,0,0);
	cout<<ans<<endl;
}
bool cmp(int x,int y)
{
	return x>y;
}
void solve2()
{
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++)
	{
		ans+=a[i];
	}
	cout<<ans<<endl;
}
void solve3()
{
	int cha[N]={0};
	for(int i=1;i<=n;i++)
	{
		ans+=a[i];
		cha[i]=a[i]-b[i];
	}
	sort(cha+1,cha+n+1);
	for(int i=1;i<=n/2;i++)
	{
		ans-=cha[i];
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		int f=1,f2=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0)
			{
				if(c[i]!=0)
				{
					f2=0;
				}
				f=0;
			}
		}
		if(n<=30)
		{
			solve1();
		}else if(f==1)
		{
			solve2();
		}else if(f2==1)
		{
			solve3();
		}
	}
	return 0;
}
