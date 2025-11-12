#include<bits/stdc++.h>
using namespace std;
#define int long long

inline int read()
{
	int x=0,r=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') r=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*r;
}

int n;
int a[100005],b[100005],c[100005];
int nw[100005];
int c1=0,c2=0,c3=0;

priority_queue<int,vector<int>,greater<int> > d;

void work()
{
	n=read();
	c1=0;
	c2=0;
	c3=0;
	while(d.size()) d.pop();
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=read();
		c[i]=read();
		if(a[i]>=b[i]&&a[i]>=c[i])
		{
			c1++;
			nw[i]=1;
			sum+=a[i];
		}
		else if(b[i]>=a[i]&&b[i]>=c[i])
		{
			c2++;
			nw[i]=2;
			sum+=b[i];
		}
		else
		{
			c3++;
			nw[i]=3;
			sum+=c[i];
		}
	}
	int ned=0;
	ned=max(c1,max(c2,c3))-n/2;
	int u=0;
	if(c1>n/2) u=1;
	else if(c2>n/2) u=2;
	else if(c3>n/2) u=3;
	for(int i=1;i<=n;i++)
	{
		if(nw[i]==u)
		{
			int k=0;
			if(u==1) k=max(b[i],c[i]);
			else if(u==2) k=max(a[i],c[i]);
			else k=max(a[i],b[i]);
			d.push(max(a[i],max(b[i],c[i]))-k);
		}
	}
	for(int i=1;i<=ned;i++)
	{
		sum-=d.top();
		d.pop();
	}
	printf("%lld\n",sum);
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	T=read();
	while(T--) work();
	return 0;
}
