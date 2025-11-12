#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,k;
int ans;
int a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int b=0;
		for(int j=i;j<=n;j++)
		{
			b^=a[j];
			if(b==k)
			{
				ans++;
				i=j;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
