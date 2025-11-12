#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a[1000];
	int a1=0,a2[1000],a3=0;
	while(scanf("%s",&a[a1])==1)
	{
		if("0"<=a[a1]&&a[a1]<="9")
		{
			a2[a3]='a[a1]'-68;
			a3++;
		}
		a1++;
	}
	for(int i=a3-1;i>0;i--)
	{
		for(int k=0;k<i;k++)
		{
			if(a2[i]>a2[k])
			{
				int aa;
				aa=a2[i];
				a2[i]=a2[k];
				a2[k]=aa;
			}
	    } 
		 printf("%d",a2[i]);
	}
 } 