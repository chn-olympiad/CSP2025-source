#include<bits/stdc++.h>
#define int long long
#define unint unsigned long long 
using namespace std;

inline int read()
{
	int n=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') 
	{
		if(c=='-')
		{
			f=-1;
			c=getchar();
		}
	}
	while(c>='0'&&c<='9')
	{
		n=(n<<3)+(n<<1)+(c^48);
		c=getchar();
	}
	return n*f;
}

inline bool cmp(int a,int b)
{
	return a>b;
}

int n,m;
int s[10005],R;
int x,y;

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n*m;i++)
	    s[i]=read();
	R=s[1];
	sort(s+1,s+1+n*m,cmp);
	int p=0;
	for(int i=1;i<=n*m;i++)
		if(s[i]==R)
		{
			p=i;
			break;
		}
	if(p%n==0)
	    x=p/n;
	else 
	    x=(p/n)+1;
	if(x%2==1)
		y=p-(x-1)*n;
	else
		y=n-(p-(x-1)*n)+1;
	printf("%lld %lld",x,y);
	return 0;
}
