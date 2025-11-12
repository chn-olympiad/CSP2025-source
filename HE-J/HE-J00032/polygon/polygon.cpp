#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;
	short f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
int n,a[5005];
long long s[5005],ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
        s[i]=s[i-1]+a[i];	
	}
	sort(a+1,a+1+n);
	if(n==1||n==2)
	  cout<<0;
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>a[3]*2)
		  cout<<1;
		else 
		  cout<<0;
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if((i==1&&s[j]>a[j]*2)||(s[j]-s[i-1]>a[j]*2))
			   ans++;
	cout<<ans+n/2;
	return 0;
}
