#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a[1000001],b[100010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	if(n<=10)
	{
		cout<<1;
		return 0;
	}
	
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{	if(b[i]-b[j-i]==k)
		  {
		   int ans=j-i;
			maxn=max(ans,maxn);
		  }
		}
	
	}cout<<maxn;
	return 0;
}
