#include <bits/stdc++.h>
using namespace std;
long long L[10005],R[10005],n,k,x,y,a[10005],sum[10005],num;
int main()	
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;	
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i];	
	}
	for(long long i=1;i<=n;i++)
	{
		sum[i-1]=0;
		for(long long j=i;j<=n;j++)
		{	
			sum[j]=sum[j-1]^a[j];
			if(sum[j]==k)
			{
				L[num]=i;
				R[num]=j;	
				num++;
			}
		}	
	}
	x=0;
	num=0;
	for(long long i=0;i<=n;i++)
	{
		if(R[i]==0)break;
		if(L[i]>x)
		{
			num++;
			x=R[i];
		}
	}
	cout << num;
	return 0;
}
