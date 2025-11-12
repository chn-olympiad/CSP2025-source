#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int c,a[10],b[10],j;
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
		for(j=0;j<10;j++)
			if(a[i]==1||a[i]==2||a[i]==3||a[i]==4||a[i]==5||a[i]==6||a[i]==7||a[i]==8||a[i]==9)
				b[j]=a[i];
	}
	for(int i=0;i<10;i++)
	{	
			if(b[i+1]>b[i])
			{
				c=b[i];
				b[i]=b[i+1];
				b[i+1]=c;
		}	
	}
	for(int i=0;i<10;i++)
	{
		cout<<b[i];
	}
}
