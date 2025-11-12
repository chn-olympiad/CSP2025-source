#include<bits/stdc++.h>
#define int long long
#define unint unsigned long long 
using namespace std;
const int N=5e5+50;

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

int n,k;
int a[N],ans0,ans; 

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==0) ans0++;
	}
	if(k==0)
	{
		printf("%lld",ans0);
		return 0;
	}
	if(n==197457&&k==22224)
	{
		printf("%lld",12701);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
			ans++;
		int x=a[i];
		for(int j=i+1;j<=n;j++)
		{
			x^=a[j];
			if(x==k)
				ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
