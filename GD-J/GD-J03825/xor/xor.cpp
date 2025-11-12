#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,k;
int total;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(int l=1;l<=n;l++)
	{
		int sum=0;
		for(int r=l;r<=n;r++)
		{
			sum^=a[r];
			if(sum==k)
			{
				total++;
				l=r;
				break;
			}
		}
	}
	
	printf("%d",total);
	return 0;
} 

