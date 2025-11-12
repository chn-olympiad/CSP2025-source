#include<bits/stdc++.h>
using namespace std;
#define int long long
int z,x,a[1005],R,q;
signed main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&z,&x);
	for(int i=1;i<=z*x;i++)
	{
		scanf("%lld",&a[i]);
		if(i==1)  R=a[i];
	}
	sort(a+1,a+z*x+1,greater<int>());
	for(int i=1;i<=z*x;i++)
	{
		if(a[i]==R)
		{
			q=i;
			break;
		}
	}
	int sum=0;
	for(int i=1;i<=z;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=x;j++)
			{
				sum++;
				if(sum==q)
				{
					printf("%lld %lld",i,j);
					return 0;
				}
			}
		}
		else
		{
			for(int j=x;j>=1;j--)
			{
				sum++;
				if(sum==q)
				{
					printf("%lld %lld",i,j);
					return 0;
				}
			}
		}
	}
	
	return 0;
}
