#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100005],num;
bool q=1,r=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
	  scanf("%d",&a[i]);	
	  if(a[i]==k)num++;
	  if(a[i]!=1)q=0;
	  if(a[i]>1)r=0;
	}
	if(q==1)
	{
		printf("%lld",n/2);
		return 0;
	}
	if(r==1)
	{
		if(k==1)
		{
			printf("%lld",num);
			return 0;
		}
		else
		{
			bool w=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					if(w==1)num++,w=0;
					else w=1;
				}
				else w=0;
			}
			printf("%lld",num);
			return 0;
		}
	}
	else
	printf("%lld",num);
	return 0;
} 
