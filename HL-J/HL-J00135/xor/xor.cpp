#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
long long cnt,a[5000005],b[5000005];
long long n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			sum=b[j]^b[i-1];
			if(sum==k)
			{
				cnt++;
				i=j+1;
			}
		}
	}
	cout<<cnt;
}
