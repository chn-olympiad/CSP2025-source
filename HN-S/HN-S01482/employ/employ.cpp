#include<bits/stdc++.h>
#define ll unsigned long long
#define N 502
#define mod 998244353
using namespace std;
inline int in()
{
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')w=-1;c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=s*10+c-'0';c=getchar();
	}return s*w;
}

ll n,m,b[N],c[N],ans=1;
string s;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in();m=in();
	cin>>s;
	for(int i=0;i<n;i++)b[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++)
	{
		c[i]=in();
	}
	if(m==1)
	{
		int x=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1)
			{
				x=i;break;
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]>x-1)sum++;
		}
		ans=sum;
		for(int i=1;i<=n-1;i++)
		{
			ans*=i;ans%=mod;
		}
		printf("%lld\n",ans);
	}
	else printf("0\n");
	return 0;
}

