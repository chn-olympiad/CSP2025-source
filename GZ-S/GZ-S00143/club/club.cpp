//GZ-S00143 遵义市第一中学 常圆 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int a=0,b=0,c=0;
	for(int i=1;i<=t;i++)
	{
		int g=0;
		int y=0;
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			int a1,a2,a3;
		cin>>a1>>a2>>a3;
		if(a1>a2&&a1>a3)
		{
			a++;
			g+=a1;
			
		}
		else if(a2>a1&&a2>a3)
		{
			b++;
			g+=a2;
		}
		else if(a3>a1&&a3>a2)
		{
			c++;
			g+=a3;
		}
		if(a<=n/2&&b<=n/2&&c<=n/2)
		{
			cout<<g;
		}
			
	}
}
	return 0;
 } 

