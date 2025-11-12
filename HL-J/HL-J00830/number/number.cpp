#include <cstdio>
#include<iostream>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int k=0;
	int b=a.size();
	char max='0';
	int d=0;
	for (int j=0;j<b;j++)
	{
		for (int i=0;i<b;i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				if(a[i]>=max)
				{
					max=a[i];
					d=i;
					k=1;
				}
			}
		}
		if(k==1)
		{
			cout<<max;
		}
		max='0';
		a[d]='g';
		k=0;
		}
	
	return 0;
}
