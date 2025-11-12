#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010];
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string c;
	cin>>c;
	int i;
	if(c.size()==1)
	{
		cout<<c;
	}
	else
	{
		for(i=0;i<=c.size();++i)
		{
			a[i]=c[i];
		}
		for(i=0;i<=1000;++i)
		{
			if(a[i]>a[i+1])
			{
				b[i+1]=a[i+1];
				a[i+1]=a[i];
				a[i]=b[i+1];
			}
		}
		for(i=0;i<=c.size();++i)
		{
			cout<<a[i];
		}
	}
	return 0;
}
