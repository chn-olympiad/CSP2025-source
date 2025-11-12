#include<bits/stdc++.h> 
using namespace std;
int a[100];
int m,n;
int pai(int x)
{
	int i=0;
	int o=1;
	int p=m*n;
	for(o=1;o<p;o++)
	{
		if(a[o]>x)
		{
			i++;
		}
	}
	return i+1;
}
int main()
{
	FILE *in,*out;
	in=fopen("seat3.in","r"); 
	out=fopen("seat.out","w");
	fscanf(in,"%d %d",&n,&m);
	int i=0;
	while(i<=n*m-1)
	{
		fscanf(in,"%d",&a[i]);
		i++;
	}
	int x=a[0];
	int mc=pai(x);
	int shang=mc/n;
	int yu=mc%n;
	int c,r;
	if(yu==0)
	{
		c=shang;
		if(c%2==0)
		{
			r=1;
		}
		if(c%2==1)
		{
			r=n;
		}
	}
	else
	{
		c=shang+1;
		if(c%2==0)
		{
			r=n+1-yu;
		}
		if(c%2==1)
		{
			r=yu;
		}
	}
	fprintf(out,"%d %d",c,r);
	return 0;
}
