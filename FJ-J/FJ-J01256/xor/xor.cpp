#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char b=getchar();
	long long a=0;
	for(;'0'<=b&&b<='9';)
	{
		a=a*10+b-'0';
		b=getchar();
	}
	return a;
}
long long n,k,a[501000],Sum[501000],ans,p;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(long long i=1;i<=n;i++)
	{
		a[i]=read();
		Sum[i]=Sum[i-1]^a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=p;j<i;j++)
		{
			if((long long)(Sum[i]^Sum[j])==k)
			{
				ans++,p=i;
				break;
			}
		}
	}
	cout<<ans;
}
