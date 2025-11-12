#include <iostream>
using namespace std;
int main()
{
	int n,m,sum=0,num=0;
	cin>>n;
	int s[n],c[n],p[n];
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]==0 && sum<=c[i])
		{
			num++;
		}
		else
		{
			sum++;
		}
	}
	cout<<num;
	return 0;
}
