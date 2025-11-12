#include<cstdio>
int s[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	int last=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=i;j>last;j--)
		{
			sum=(sum^s[j]);
			if(sum==k)
			{
				ans++;
				last=i;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
