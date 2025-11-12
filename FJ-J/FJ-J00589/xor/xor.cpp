#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans=1;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++)//当前枚举的区间大小 
	{
		int sum=0;
		for(int i=1;i<=k;i++)
		{
			int smallsum=a[i];
			for(int j=i;j<=k+i;j++)
			{
				smallsum=smallsum^a[j];
			}
			sum+=smallsum;
		}
		if(sum==k)
		{
			ans=max(ans,sum);
		}
	}
	
	cout<<ans;
	return 0;
}
