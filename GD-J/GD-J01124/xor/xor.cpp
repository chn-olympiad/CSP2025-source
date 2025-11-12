#include<iostream>
using namespace std;
int a[500005],s[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	int n,k,res=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=a[i]^s[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((s[j]^s[i-1])==k)
			{
				res++;
				i=j;
				break;
			}
		}
	}
	printf("%d\n",res);
	
	fclose(stdin); fclose(stdout);
	return 0;
}
