//xor.cpp
#include<bits/stdc++.h>
using namespace std;
int a[500010],n,k,num;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		for(int j=i;j<=n;j++)
		{
			ans^=a[j];
			if(ans==k)
			{
				num++;
				i=j;//i=j+1
				break;
			}
		}
	}
	printf("%d",num);
	return 0;
}
