#include<bits/stdc++.h>
using namespace std;
string a,b;
void wyn(string x)
{
	int m=x.size();
	for(int k=1;k<=1000000;k++)
	{
		for(int i=1;i<=m;i++)
		{
			if(x[i]>=x[i-1])
			{
				swap(x[i],x[i-1]);
			}
		}
	}
	cout<<x;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i=1;
	char n;
	while(cin>>n)
	{
		a[i]=n;
		if(a[i]>='0' && a[i]<='9')
		{
			b[i]=a[i];
		}
		i++;
	}
	wyn(b);
	return 0;
}
