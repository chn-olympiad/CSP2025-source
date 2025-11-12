#include<bits/stdc++.h>
using namespace std;
//ji de shan zu shi;
const int N=1e5+50;
int t,n,nn;
struct people{
	int b1;
	int b2;
	int b3;
}a[N];
long long ans=0;
void dfs(int x,int a1,int a2,int a3,long long cnt)
{
	if(x>n)
	{
		ans=max(ans,cnt);
		//cout<<ans<<endl;
		return ;
	}
	for(int i=1;i<=3;++i)
	{
		if(i==1&&a1<nn)
		{
			dfs(x+1,a1+1,a2,a3,cnt+a[x].b1);
			dfs(x+1,a1,a2,a3,cnt);
		}
		if(i==2&&a2<nn)
		{
			dfs(x+1,a1,a2+1,a3,cnt+a[x].b2);
			dfs(x+1,a1,a2,a3,cnt);
		}
		if(i==3&&a3<nn)
		{
			dfs(x+1,a1,a2,a3+1,cnt+a[x].b3);
			dfs(x+1,a1,a2,a3,cnt);
		}
	}
}
void bfs(int x,int a1,int a2,long long cnt)
{
	if(a1==nn&&a2==nn)
	{
		ans=max(ans,cnt);
		//cout<<ans<<endl;
		return ;
	}
	if(x>n)
	{
		ans=max(ans,cnt);
		//cout<<ans<<endl;
		return ;
	}
	for(int i=1;i<=2;++i)
	{
		if(i==1&&a1<nn)
		{
			bfs(x+1,a1+1,a2,cnt+a[x].b1);
			bfs(x+1,a1,a2,cnt);
		}
		if(i==2&&a2<nn)
		{
			bfs(x+1,a1,a2+1,cnt+a[x].b2);
			bfs(x+1,a1,a2,cnt);
		}
	}
}
bool pan(people x,people y)
{
	return x.b1>y.b1;
}
//ji de shan zu shi;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ji de shan zu shi;
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		int c2=0,c3=0;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i].b1>>a[i].b2>>a[i].b3;
			if(a[i].b2!=0)
			{
				c2++;
			}
			if(a[i].b3!=0)
			{
				c3++;
			}
		}
		if(c2==0&&c3==0)
		{
			sort(a+1,a+n+1,pan);
			nn=n/2;
			for(int i=1;i<=nn;i++)
			{
				ans+=a[i].b1;
			}
			cout<<ans<<endl;
		}
		else if(c3==0)
		{
			nn=n/2;
			bfs(1,0,0,0);
			cout<<ans<<endl;
			for(int i=1;i<=n;++i)
			{
				a[i].b1=0;
				a[i].b2=0;
			}
		}
		else
		{
			nn=n/2;
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			for(int i=1;i<=n;++i)
			{
				a[i].b1=0;
				a[i].b2=0;
				a[i].b3=0;
			}
		}
	}
	//ji de shan zu shi;
	return 0;
}
