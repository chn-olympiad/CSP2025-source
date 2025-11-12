#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
/*void find(int x)
{
	bool fg=0;
	int tmp=a[x];
	for(int i=1;i<=n;i++)
	{
		for(int j=x+1;j<x+i;j++)
		{
			tmp^=a[j];
		}
		if(tmp==k)
		{
			fg=1;
			find(x+i);
			ans++;
		}
	}
	if(!fg)find(x+1);
	return ;
}*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(!k)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			{
				int c=0;
				while(a[i]==1)
				{
					i++;c++;
				}
				ans+=c/2;
				i--;
			}
			else ans++;
		}
	}
	else for(int i=1;i<=n;i++)if(a[i])ans++;
	printf("%d",ans);
	return 0;
}
