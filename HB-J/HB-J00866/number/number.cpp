#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","s",stdin);
	freopen("number.out","z",stdout);
	string s,t;
	cin>>s;
	char a[10000005]={};
	char b[10000005]={};
	int c[10000005]={};
	int n=0;
	int x,y;
	char z;
	for(int i=0;i<s.size();i++)
	{
		a[i]=s[i];
	}
	for(int j=0;j<s.size();j++)
	{
		if(a[j]>='0'&&a[j]<='9')
		{
			b[n]=a[j];
			n+=1;
		}
	}
	for(int k=0;k<=n;k++)
	{
		if(b[k]=='0')
		{
			c[k]=0;
		}
		if(b[k]=='1')
		{
			c[k]=1;
		}
		if(b[k]=='2')
		{
			c[k]=2;
		}
		if(b[k]=='3')
		{
			c[k]=3;
		}
		if(b[k]=='4')
		{
			c[k]=4;
		}
		if(b[k]=='5')
		{
			c[k]=5;
		}
		if(b[k]=='6')
		{
			c[k]=6;
		}
		if(b[k]=='7')
		{
			c[k]=7;
		}
		if(b[k]=='8')
		{
			c[k]=8;
		}
		if(b[k]=='9')
		{
			c[k]=9;
		}
	}
	for(int l=0;l<=n;l++)
	{
		for(int m=l;m<=n;m++)
		{
			if(c[l]<c[m])
			{
				x=c[l];
				y=c[m];
				c[l]=y;
				c[m]=x;
			}
		}
	}
	for(int o=0;o<=n;o++)
	{
		if(c[o]==0)
		{
			z=z+'0';
		}
		if(c[o]==1)
		{
			z=z+'1';
		}
		if(c[o]==2)
		{
			z=z+'2';
		}
		if(c[o]==3)
		{
			z=z+'3';
		}
		if(c[o]==4)
		{
			z=z+'4';
		}
		if(c[o]==5)
		{
			z=z+'5';
		}
		if(c[o]==6)
		{
			z=z+'6';
		}
		if(c[o]==7)
		{
			z=z+'7';
		}
		if(c[o]==8)
		{
			z=z+'8';
		}
		if(c[o]==9)
		{
			z=z+'9';
		}
	}
	cout<<z<<endl;
	return 0;
}
