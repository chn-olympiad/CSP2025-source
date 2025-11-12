#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005],x;int b[200005],c[200005],t=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		x=a[i];
		if(x==k)
		{
			b[t]=c[t]=i;
			t++;
		}
		for(int j=i+1;j<=n;j++)
		{
			x^=a[j];
			if(x==k)
			{
				b[t]=i;
				c[t++]=j;
			}
		}
	}
	cout<<t-1;
	return 0;
}
