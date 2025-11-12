#include<bits/stdc++.h>
using namespace std;
int n, m, k, a[5], num1, b,num=10000000000;
int main()
{
	freopen("road1.in","r",stdin);
	freopen("road1.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[1]>>a[2]>>a[3];
	}
	for(int i=1;i<=k;i++)
	{
		num1=0;
		for(int j=1;j<=n+1;j++)
		{
			cin>>b;
			num1+=b;
		}
		if(num1<num)
		{
			num=num1;
		}
	}
	cout<<num;
	return 0;
}
