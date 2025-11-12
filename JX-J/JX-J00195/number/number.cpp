#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[10000];
	int b[100000],c=0,d=0;
	while(cin>>a[d++])
	{
	}
	for(int i=0;i<d;i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			b[c++]=a[i]-48;
		}
	}
	for(int i=0;i<c;i++)
	{
		int max=-1,maxj;
		for(int j=0;j<c;j++)
		{
			if(b[j]>max)
			{
				max=b[j];
				maxj=j;
			}
		}
		cout<<max;
		b[maxj]=-1;
		}
	
	return 0;
}
