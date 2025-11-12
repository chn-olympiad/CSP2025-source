#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t>>n;
	for(int i=1;i<=t;i++)
	{
		int num=0;
		for(int j=1;j<=n;j++)
		{
			int a[5]={0,0,0,0,0};
			int sum=0;
			int x=0;
			for(int k=1;k<=3;k++)
			{
				cin>>a[k];
				if(a[k]>x)
				{
					x=a[k];
				}
			}
			sum+=x;
			num+=sum;
		}
		cout<<num<<endl;
	}
	return 0;
}
