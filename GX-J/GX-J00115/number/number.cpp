#include<bits/stdc++.h>
using namespace std;
string b;
long long a[10000005],j=0,i;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(i=0;i<b.size();i++)
	{
		if(b[i]>='0'&&b[i]<='9')
		{
			a[j]=b[i]-48;
			j++;
		}
	}
	for(i=0;i<j-1;i++)
	{
		for(int k=i;k<j;k++)
		{
			if(a[k]>a[i])
			{
				swap(a[k],a[i]);
			}
		}
	}
	for(i=0;i<j;i++)
	{
		cout<<a[i];
	}
	return 0;
}
