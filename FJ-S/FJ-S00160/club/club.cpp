#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans,maxn=0;
struct jk{
	int x,y,z;
}a[100001];
struct jj{
	int x,y;
}f[4];
int read()
{
	int ans=0,w=1;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-')
		 w=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9')
	{
		ans*=10;
		ans+=ch-'0';
		ch=getchar();
	}
	return ans*w;
}
void js(int x)
{
	if (x==n+1)
	{
		ans=f[1].y+f[2].y+f[3].y;
		maxn=max(maxn,ans);
		return;
	}
	if (f[1].x<(n/2))
	{
		f[1].y+=a[x].x;
		f[1].x++;
		js(x+1);
		f[1].y-=a[x].x;
		f[1].x--;
	}
	if (f[2].x<(n/2))
	{
		f[2].y+=a[x].y;
		f[2].x++;
		js(x+1);
		f[2].y-=a[x].y;
		f[2].x--;
	}
	if (f[3].x<(n/2))
	{
		f[3].y+=a[x].z;
		f[3].x++;
		js(x+1);
		f[3].y-=a[x].z;
		f[3].x--;
	}
	return;
}
bool cmp1(jk x,jk y)
{
	return x.x>y.x;
}
bool cmp2(jk x,jk y)
{
	if (x.x==y.x)
	 return x.y<y.y;
	return x.x>y.x;
}
int main()
{
	freopen("club.in","r",stdin);
	/**/freopen("club.out","w",stdout);
	t=read();
	while (t--)
	{
		maxn=0;
		n=read();
		int t=0;
		for (int i=1;i<=n;i++)
		{
			a[i].x=read(); a[i].y=read(); a[i].z=read();
		    if (a[i].y!=0)
		     t=1;
		    if (a[i].z!=0)
		     t=2;
		}
		/**/if (t==0)
		{
			sort(a+1,a+1+n,cmp1);
			for (int i=1;i<=n/2;i++)
			 maxn+=a[i].x;
		}
		else if (t==1)
		{
			sort(a+1,a+1+n,cmp2);
			for (int i=1;i<=n/2;i++)
			 maxn+=a[i].x;
			for (int i=n/2+1;i<=n;i++)
			 maxn+=a[i].y;
		}
		else
		 js(1);
		cout<<maxn<<endl;
	}
	return 0;
}
/*3
4
4 2 1  
3 2 4  
5 3 4  
3 5 1 
18 
4
0 1 0
0 1 0
0 2 0
0 2 0
4
2
10 9 8
4 0 0
13*/
/*1
6
10 9 0
10 1 0
10 1 0
10 0 0
10 9 0
10 2 0
33*/
