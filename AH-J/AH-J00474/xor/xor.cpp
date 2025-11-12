#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k; scanf("%d %d",&n,&k);
	int flag1=1,flag2=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1) flag1=0;
		if(a[i]>1) flag2=0;
	}
	if(k==0&&flag1)
	{
		printf("%d\n",n/2);
		return 0;
	}
	if(k==0&&flag2)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) sum++;
			if(a[i]==1&&a[i+1]==1) sum++,i++;
		}
		printf("%d\n",sum);
		return 0;
	}
	if(k==1&&flag2)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			if(a[i]==1) sum++;
		printf("%d\n",sum);
		return 0;
	}
	return 0;
}
