#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct node
{
	long long a,b,c;
}a[100010];
long long t,n;

bool cmp(node a,node b)
{
	return a.a-a.b>b.a-b.b;
}

bool ff=1;
long long ans=0;

void dfs(long long id,long long sum,long long x,long long y,long long z)
{
	if(id==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(x<n/2)dfs(id+1,sum+a[id].a,x+1,y,z);
	if(y<n/2)dfs(id+1,sum+a[id].b,x,y+1,z);
	if(z<n/2)dfs(id+1,sum+a[id].c,x,y,z+1);
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
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c)ff=0;
		}
		if(ff)
		{
			sort(a+1,a+1+n,cmp);
			for(long long i=1;i<=n/2;i++)ans+=a[i].a;
			for(long long i=n/2+1;i<=n;i++)ans+=a[i].b;
			cout<<ans<<endl;
		}
		else
		{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
	}
}

/*#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct node
{
	long long a,b,c;
}a[100010];
long long T,n,t[3],f[1010],ans;

bool cmp(node a,node b)
{
	return a.a-a.b>b.a-b.b;
}

long long main()
{
	long long aa=1;
	for(long long i=0;i<10;i++)aa*=3;
	cout<<aa;
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(f,0,sizeof(f));
		ans=0;
		cin>>n;
		for(long long i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
		sort(a+1,a+1+n,cmp);
		for(long long i=1;i<=n;i++)
		{
			for(long long j=min(i,n/2);j>=0;j--)
			{
				if(!j)
				{
					if(i<=n/2)f[j]=f[j]+a[i].a;
					else f[j]=f[j]+a[i].b;
				}
				else
				{
					if(i<=n/2)f[j]=max(f[j-1]+a[i].c,f[j]+a[i].a);
					else f[j]=max(f[j-1]+a[i].c,f[j]+a[i].b);
				}
				ans=max(ans,f[j]);
			}
		}
		cout<<ans<<endl;
	}
}
/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
