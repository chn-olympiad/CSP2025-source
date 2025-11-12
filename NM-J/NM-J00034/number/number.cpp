#include<bits/stdc++.h>
using namespace std;
int b[1000010];
int qh(int g,int u)
{
	for(int i=1;i<=u;i++) g=g*10;
	return g;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s,l=0,i,j,h,e,t,c;
	scanf("%d",&s);
	t=s;
	while(t!=0)
	{
		t/=10;
		l++;
	}
	for(i=1;i<=l;i++)
	{
		b[i]=s%10;
		s=s/10;
	}
	e=l;
	for(i=1;i<=l;i++)
	{
		int max=0;
		for(j=1;j<=l;j++)
		{
			if(b[j]>max)
			{
				max=b[j];
				c=j;
			}
		}
		e--;
		h=h+qh(b[c],e);	
		b[c]=0;
	}
	printf("%d",h);
	return 0;
}
