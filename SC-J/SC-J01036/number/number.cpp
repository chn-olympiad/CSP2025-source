#include<bits\stdc++.h>
#include<iostream>
using namespace std;
string a,b;
int main()
{
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);

	int l=0;
	char x;
	int z=a.size();
	for(int i=0;i<z;i++)
	{
			if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')
			{
				b[l++]=a[i];
			} 
	}
	for(int i=0;i<=l;i++)
	{
		for(int j=l;j>=i;j--)
		{
			if(b[i]<b[j])
			{
				x=b[i];
				b[i]=b[j];
				b[j]=x;
				
			}
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 