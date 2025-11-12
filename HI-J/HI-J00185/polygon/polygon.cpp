#include<bits/stdc++.h>
using namespace std;
int a[60];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int m=0;
	int m1=0;
	cin>>n;
	int c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>m)
		{
			c=i;
			m=a[i];
		}
		m1+=a[i];
	}
	m1-=a[c];
	if(m1>a[c])
	{
		cout<<"1";
	}
	else if(m1<a[c] || m1==a[c])
	{
		cout<<"0";
	}
	return 0;
}
