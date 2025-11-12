#include<bits/stdc++.h>
using namespace std;
int n,k,a,aa[500005],f[500005],dis,l=1,kk;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	dis=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		for(int j=l;j<=i;j++)
		{
			aa[j]=aa[j]^a;
		    if(aa[j]==k)
		    {
		    	f[i]=dis+1;
			}
		}
		if(f[i]>dis)
		{
			l=i+1;
			dis++;
		}
	}
	printf("%d",dis);
	return 0;
 } 
