#include<bits/stdc++.h>
using namespace std;
int sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b>c)
		{
			sum++;
		}
		if(a+c>b)
		{
			sum++;
		}
		if(b+c>a)
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}