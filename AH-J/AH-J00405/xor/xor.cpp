#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500024],b[1024][1024],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long x=0;x<n;x++)
	{
		for(long long y=x;y<n;y++)
		{
			long long m=0;
			for(long long l=x;l<=y;l++)
			{
				m^=a[l];
			}
			b[x][y]=m;
		}	
	}
	long long e=-1;
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<n;j++)
		{
			if(j>i)
			{
				continue;
			}
			if(b[j][i]==k&&j>e)
			{
				e=i;
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
