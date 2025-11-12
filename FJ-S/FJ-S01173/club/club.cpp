#include<bits/stdc++.h>
using namespace std;
int a[100000+10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,zuida=-10000,s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[j];
			if(a[j]>zuida)
			{
				zuida=a[j];
			}
		}
		s=s+zuida;
	}
	cout<<s;
	return 0;
}

