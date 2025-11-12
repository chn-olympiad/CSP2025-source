#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000000],d[1000000],e;
	int b=9,c=1;
	cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9];
	for(int i=1;i<=b;i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			d[c]=a[i];
			c++;
		}
	}
	for(int i=1;i<=c;i++)
	{
		for(int j=1;j<c;j++)
		  if(d[j]<d[j+1])
		  {
			e=d[j];
			d[j]=d[j+1];
			d[j+1]=e;
		  }
	}
	for(int i=1;i<=c;i++)
	{
		cout<<d[i];
	}
	return 0;
}