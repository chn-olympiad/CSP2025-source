#include<bits/stdc++.h>
#define int long long
#define unint unsigned long long 
using namespace std;
const int N=10000,mod=998244353;

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

int n;
int a[N];
int ans;

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	int sum=a[1]+a[2];
	int s=sum;
	for(int i=2;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			sum+=a[j];
			if(sum>a[j]*2) ans++,ans%=mod;
			for(int z=j+1;z<=n;z++)
			{
				if(sum+a[z]>a[z]*2) ans++,ans%=mod;
			}
		}
		sum=s+a[i+1];
	}
	printf("%lld",ans%mod);
	return 0;
}
