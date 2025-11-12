#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0' and a[i]<='9')
		{
			b+=a[i];
		}
	}
	for(int i=b.size();i>=1;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(b[j]<b[j+1])
			{
				swap(b[j],b[j+1]);
			}
		}
	}
	cout<<b;
	return 0;
}
