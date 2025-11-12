#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1010,mod=998244353;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m;
string s;
int a[N];
int t[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	if(m==n)
	{
		int sum=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||a[i]==0)
			{
				puts("0");
				return 0; 
			}
		}
		for(int i=1;i<=n;i++) sum=sum*i%mod;
		cout<<sum<<endl;
		return 0;
	}
	else if(m==1)
	{
		int sum=1,flag=0;
		if(s[1]=='1')
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]=='0')
				{
					flag=1;
					break;
				}
			}
			if(!flag)
			{
				for(int i=1;i<=n;i++) sum=i*sum%mod;
				cout<<sum<<endl;
				return 0;
			}
			else
			{
				puts("0");
				return 0;
			}
		}
		else
		{
			puts("0");
			return 0;
		}
	}
	else
	{
		puts("0");
		return 0;
	}
	return 0;
}
//Bocchi the Rock!
