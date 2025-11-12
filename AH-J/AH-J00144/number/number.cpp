#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
long long sum[10];
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<MAXN;++i)
	{
		if(a[i]>='0'&&a[i]<='9') sum[a[i]-'0']++;
		else if(a[i]>'z'||a[i]<'a') 
		{
			for(i=9;i>=0;--i)
			{
				for(long long j=1;j<=sum[i];++j)
				{
					printf("%lld",i);
				}
			}
			return 0;
		}
		
	}
	for(long long i=9;i>=0;--i)
	{
		for(long long j=1;j<=sum[i];++j)
		{
			printf("%lld",i);
		}
	}
	return 0;
}
