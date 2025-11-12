#include<bits/stdc++.h>
using namespace std;
char s[1000000];
char b[1000000];
char f[1000000];
int p=0;
void qu(int x)
{
	int n=0,i=0;
	for(n=0;n<x;n++)
	{
		if(s[n]>=48&&s[n]<=57)
		{
			b[i]=s[n];
			i++;
		}
	}
}
void pai()
{
	char a;
	int i=1;
	int j=1;
	int o=strlen(b);
	while(j<o)
	{
		i=j;
		while(i<o)
		{
			if(b[i]>b[i-1])
			{
				a=b[i];
				b[i]=b[i-1];
				b[i-1]=a;
			}
			i++;
		}
		j++;
	}
	i=1;
	j=1;
	while(j<o)
	{
		i=j;
		while(i<o)
		{
			if(b[i]>b[i-1])
			{
				a=b[i];
				b[i]=b[i-1];
				b[i-1]=a;
			}
			i++;
		}
		j++;
	}
}
int main()
{
	FILE *in,*out;
	in=fopen("number.in","r");
	out=fopen("number.out","w");
	fscanf(in,"%s",&s);
	int x=strlen(s);
	qu(x);
	pai();
	fprintf(out,"%s",b);
	return 0;
}
