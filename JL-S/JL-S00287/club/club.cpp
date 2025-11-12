#include<bits/stdc++.h>
using namespace std;
#define N 100010
long long arr[N],m[N];
long long t,n,sum = -1,num=0,cnt=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=0;i<n;i++)
		{
			for(int j = 0;j<3;j++)
			{
			scanf("%lld",&arr[j]);
			if(j==0) 
			{
			sum++;
			m[sum] = arr[0];
			
		}
			if(j!=0&&arr[j]>m[sum]) 
			{
			sum++;
			sum = sum - 1;
			m[sum] = arr[j];
		
		}
			
		}
		
		}
		for(int k = 0; k < n;k++)
		{
			num = k;
			cnt = cnt + m[num];
		}
		
		cout<<cnt<<endl;
		
		for(int i = 0; i < n; i++)
		{
			cnt = 0;
			arr[i] = 0;
			m[i] = 0;
			sum = -1;
		}
	}
	
	
	return 0;
}
