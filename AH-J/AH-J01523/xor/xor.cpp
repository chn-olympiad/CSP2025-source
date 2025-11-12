#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,f,ff,bj[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i]!=1)f=1;
		if(a[i]>1)ff=1;
	}
	if(f==0)
	{
		if(k==1)
		{
			printf("%d",n);return 0;
		}
		if(k==0)
		{
			printf("%d",n/2);return 0;
		}
		else
		{
			printf("0");return 0;
		}
	}
	else if(ff==0)
	{
		int o=0,oo=0,z=0,t=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1){o++;oo=o;}
			else{
				z++;
				if(oo%2==0)t=oo/2;
			}
		}
		if(k>1)
		{
			printf("0");
			return 0;
		}
		else if(k==1)
		{
			printf("%d",o);
			return 0;
		}
		else if(k==0)
		{
			printf("%d",z+t);
			return 0;
		}
	}
	return 0;
}
