#include <bits/stdc++.h>
using namespace std;

long long t,n,mmax;
int vis[505];
struct node
{
	int a,b,c;
}x[100005];

void dfs(int k)
{
	if(k > n)
	{
		long long sum=0,aa=0,bb=0,cc=0;			
		for(int i=1; i<=n; i++)
		{
			if(vis[i] == 1)
			{
				sum+=x[i].a;
				aa++;
			}
			else if(vis[i] == 2)
			{
				sum+=x[i].b;
				bb++;
			}
			else
			{
				sum+=x[i].c;
				cc++;
			}
		}
		
		if(aa <= n/2 && bb <= n/2 && cc <= n/2)
			mmax=max(mmax,sum);
			
		return ;
	}
	
	for(int i=1; i<=3; i++)
	{
		vis[k]=i;
		dfs(k+1);
	}
}

bool pd()
{
	for(int i=1; i<=n; i++)
	{
		if(x[i].b != 0 || x[i].c != 0)
			return false;
	}
	
	return true;
}

bool ppd()
{
	for(int i=1; i<=n; i++)
	{
		if(x[i].c != 0)
			return false;
	}
	
	return true;
}

bool cmp(node xx, node yy)
{
	if(xx.a == yy.a)
		return xx.b > yy.b;
		
	return xx.a > yy.a;
}

void js()
{
	sort(x+1,x+1+n,cmp);
	for(int i=1; i*2<=n; i++)
		mmax+=x[i].a;
}

void jjs()
{
	sort(x+1,x+1+n,cmp);
	int tx=0,xt=0;
	for(int i=1; i<=n; i++)
	{
		if(x[i].a > x[i].b && tx < n/2)
		{
			mmax+=x[i].a;
			tx++;
		}
		else if(x[i].a < x[i].b && xt < n/2)
		{
			mmax+=x[i].b;
			xt++;
		}
		else
		{
			if(tx > xt)
			{
				mmax+=x[i].b;
				xt++;
			}
			else
			{
				mmax+=x[i].a;
				tx++;
			}
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		mmax=0;
		cin>>n;
		for(int i=1; i<=n; i++)
			cin>>x[i].a>>x[i].b>>x[i].c;
			
		if(pd())
			js();
		else if(ppd())
			jjs();
		else
			dfs(1);
			
		cout<<mmax<<endl;
	}
	
	return 0;
}
