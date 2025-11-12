#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];
bool vid[500010];
long long ans;
int tot=1;
stack<int> b;
struct dd{
	long long qs=0,js=0;
}c[500010];
struct ddd{
	int u1=-1,t1=-1;
}ejz[500010];
int ys(int u,int t)
{
	
	int sum=0;
	int i=1;
	while(u!=0||t!=0)
	{
		ejz[i].u1=u%2;
		ejz[i].t1=t%2;
		u/=2;
		t/=2;
		++i;
	}
	for(int j=1;j<=i;j++)
	{
		if((ejz[j].t1==0&&ejz[j].u1==1)||(ejz[j].t1==1&&ejz[j].u1==0))
		{
			int zz=1;
			for(int uu=1;uu<j;uu++)
			{
				int z=uu;
				while(z--)
				{
					zz=zz*2;
				}
			}
			sum=sum+zz;
		}
	}
	return sum;
}
void dfs(long long qs1,long long js1)
{
	if(qs1>=js1)
	{
		return;
	}
	for(int i=qs1;i<=js1;i++)
	{
		if(vid[i+1]==1)
		{
			js1=i;	
		} 
		if(b.top()==k)
		{
			++ans;
			for(long long j=qs1;j<=i;j++)
			{
				vid[j]=1;
			}
			dfs(i+1,js1);
			return;
		}
		if(b.empty())
		{
			b.push(a[i]);
		} 
		else
		{
			int o=ys(b.top(),a[i]);
			b.pop();
			b.push(o);
		}
	}
	dfs(qs1+1,js1);
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			++ans;
			vid[i]=1;
		} 
	}
	if(vid[1]!=0)
	c[tot].qs=1;
	else
	{
		for(int i=2;i<=n;i++)
		{
			if(vid[i]==0)
			{
				c[tot].qs=i;
			}
		}
	}
	for(int i=c[1].qs;i<n;i++)
	{
		if(vid[i]==1)
		{
			c[tot].js=i;
			++tot;
			c[tot].qs=i+1;
		}
	}
	if(vid[n]==0)
	{
		c[tot].js=n;
	}
	for(int i=1;i<=tot;i++)
	{
		dfs(c[tot].qs,c[tot].js);
	}
	cout<<ans;
	return 0;
}