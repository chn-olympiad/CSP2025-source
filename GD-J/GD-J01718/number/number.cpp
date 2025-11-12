#include<bits/stdc++.h>
using namespace std;
int c[1000000],i;
char a[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int j=0;a[j];j++)
	{
		if(a[j]>='0'&&a[j]<='9')
		{
			c[i]=a[j]-48;
			i++;
		}
	}
	sort(c,c+i);
	for(int j=i-1;j>=0;j--)
	{
		cout<<c[j];
	}
	return 0;
}
