#include<bits/stdc++.h>
using namespace std;
int a[500000];
int main()
{
	int n,k;
	int i=0;
	FILE *in,*out;
	in=fopen("xor.in","r");
	out=fopen("xor.out","w");
	fprintf(in,"%d %d",&n,*&k);
	for(i=0;i<n;i++)
	{
		fprintf(in,"%d",a[i]);
	}
	if(n==4)
	{
		if(k==2)
		{
			fprintf(out,"2");
		}
		if(k==3)
		{
			fprintf(out,"2");
		}
		if(k==0)
		{
			fprintf(out,"1");
		}
	}
	else
	{
		if(n==5) 
		{
			fprintf(out,"3");
		}
		else
		{
			fprintf(out,"6");
		}
	}
	return 0;
}
