#include<bits\stdc++.h>
using namespace std;
int a[100],b[100];
int main()
{
	freopen("polygon1.in","r",stdin);
	freopen("polygon1.out","w",stdout);
	int n,s=0,s1=0,s2=0,ma=0,l=0,x=1;
	for(int i=0;i<n;i++)
	{
		b[i]==1;
	}
	for(int i=3;i<=n;i++)
	{
		x=i;
		while(b[0]<=n)
		{

			for(int j=0;j<=x;j++)
			{
				s=s+a[b[j]];
				s2++;
				if(ma<a[b[j]])
				{
					ma=a[b[j]];
				}	
			}
			if(ma<s-ma)
			{
			s1++;
			}
			if(b[x]==n-1)
			{
				b[x-1]++;
				b[x]=0;
			}
			b[x]++;
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}