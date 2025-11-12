#include<bits/stdc++.h>
using namespace std;
int main()
{
int max,accont=0,a;
char c[101000];
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>c;
for(int i=0;i<strlen(c);i++)
{
	a=(c[i]);
	if(a>=48&&a<=57)
	accont+=1;
}
int b[101000]={0},j=1;
for(int i=0;i<strlen(c);i++)
{
	a=(c[i]);
	a-=48;
	if(a>=0&&a<=9)
	{
		b[j]=a;
		j++;
	}
}
for(int i=1;i<=accont;i++)
{
	for(int j=1;j<=accont;j++)
	{
		if(b[j]<b[j+1])
		{
			max=b[j+1];
			b[j+1]=b[j];
			b[j]=max;
		}
	}
}
for(int i=1;i<=accont;i++)
{
	cout<<b[i];
}
}