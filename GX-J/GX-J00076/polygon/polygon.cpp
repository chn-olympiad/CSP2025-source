#include<bits/stdc++.h>
using namespace std;
int a[5001],n,sum=0;
bool b[5001];
void sth(int a,int i)
{
	if(i==n)
	{
		int x=0;
		for(int i=0;i<n;i++)
		{
			x+=b[i];
		}
		if(x<3)
		{
			return ;
		}
		sort(a,a+n);
		int num=0;
		for(int i=0;i<n;i++)
		{
			num+=a[i];
		}
		if(num<=a[n]*2)
		{
			return ;
		}
		sum++;
	}
	b[i]=1;
	sth(a,i+1)
	b[i]=0;
	sth(a,i+1)
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<sth(a,1);
	return 0;
}
