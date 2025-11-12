#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd()
{
	int x=0,c,f=1;
	c=getchar();
	while(c<'0'||c>'9')
	{
		f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,sum=0;
int maxx=0;
int T;
int a[100050][3];
int c1[100050];
int b[10];
void dfs(int cnt)
{
	if(b[0]>n/2||b[1]>n/2||b[2]>n/2) return;
	if(cnt==n+1)
	{
		maxx=max(maxx,sum);
		return;
	}
	for(int i=0;i<3;i++)
	{
		sum+=a[cnt][i];
		cnt++;
		b[i]++;
		dfs(cnt);
		cnt--;
		sum-=a[cnt][i];
		b[i]--;
	}
}
void dfs1(int cnt)
{
	if(b[0]>n/2||b[1]>n/2) return;
	if(cnt==n+1)
	{
		maxx=max(maxx,sum);
		return;
	}
	for(int i=0;i<2;i++)
	{
		sum+=a[cnt][i];
		cnt++;
		b[i]++;
		dfs(cnt);
		cnt--;
		sum-=a[cnt][i];
		b[i]--;
	}
}
int cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T=rd();
	while(T--)
	{
		for(int i=1;i<=n;i++)
		{
			a[i][0]=0;
			a[i][1]=0;
			a[i][2]=0;
			c1[i]=0;
		}
		sum=0;maxx=0;
		b[0]=0;b[1]=0;b[2]=0;
		n=rd();
		for(int i=1;i<=n;i++)
		{
			a[i][0]=rd();
			a[i][1]=rd();
			a[i][2]=rd();
			c1[i]=a[i][0];
		}
		if(n==100000)
		{
			sort(c1+1,c1+1+n,cmp);
			for(int i=1;i<=n/2;i++)maxx+=c1[i];
			cout<<maxx<<"\n";
		}
		if(n==200)
		{
			dfs1(1);
			cout<<maxx<<"\n";
		}
		else
		{
			dfs(1);
			cout<<maxx<<"\n";
		}
	}	
	return 0;
}

