#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read();

int n,m,xxx,a[111],x;

bool cmp(int p,int q)
{
	return p>q;
}

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++) a[i]=read();
	xxx=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==xxx)
		{
			x=i;
			break;
		}
	}
	if(x<=n) printf("1 %lld",x);
	else if((x/n)%2==0&&x%n!=0) printf("%lld %lld",x/n+1,x%n);
	else if((x/n)%2==0&&x%n==0) printf("%lld 1",x/n);
	else if((x/n)%2==1&&x%n!=0) printf("%lld %lld",x/n+1,n-x%n+1);
	else if((x/n)%2==1&&x%n==0) printf("%lld %lld",x/n,n);
	return 0;
}

inline int read()
{
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

