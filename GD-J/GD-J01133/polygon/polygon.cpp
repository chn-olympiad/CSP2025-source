#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b[4],sum,m=0;
	cin>>a;
	for(int i=1;3>=i;i++)
	{
		cin>>b[i];
		if(b[i]>m)
		{
			m=b[i];
		}
		sum+=b[i];
	}
	if(sum<=m*2)
	{
		cout<<0;
	}
	else
	{
		cout<<1;
	}
	return 0;
}
