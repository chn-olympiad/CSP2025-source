#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in.txt","r",stdin);
	freopen("number.out.txt","w",stdout);
	struct s;
    getchar(s);
	int b,f=0;
	b=strstr(s);
	char a[b+1],d[b+1];
	int c[b+1];
	a=s;
	for(int i=0;i<=b;i++)
	{
		c[i]=a[i];
		if(c[i]>=48&&c[i]<=57)
		{
			d[f]=a[i];
			f++;
		}
	}
	int g=f,max=-9999,x=0;
	for(int i=0;i<=f;i++)
	{
		max=-9999;
		for(int j=0;j<=g;j++)
		{
			if(d[j]>max) max=d[j];
		}
		g--;
		x+=max;
		x*=10;
	}
    cout<<x<<endl;
} 