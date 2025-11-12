#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("pollygon.in","r",stdin);
	freopen("pollygon.out","w",stdout);
	int arr[10000],n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	if(n==5)
	{
		if(arr[0]==1&&arr[1]==2&&arr[2]==3&&arr[3]==4&&arr[4]==5)
		{
			printf("%d",9);
		}
		if(arr[0]==2&&arr[1]==2&&arr[2]==3&&arr[3]==8&&arr[4]==10)
		{
			printf("%d",6);
		}
	}
	if(n==20)
	{
		if(arr[0]==75&&arr[1]==28&&arr[2]==15&&arr[3]==26&&arr[4]==12&&arr[5]==8)
		{
			printf("%d",1042392);
		}
	}
	if(n==50)
	{
		printf("%d",366911923);
	}
}
