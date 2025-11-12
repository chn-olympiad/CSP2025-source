#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n = 0;
	cin>>n;
	int s1 = 0;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	int t = 3,x= 0;
	while(t<=n)
	{
		int s = 1,s2 = 0;
		for(int i = n;i>n-t;i--)
		{
			s*=a[i];
		}
		for(int j = 1;j<=t;j++)
		{
			s2*=a[j]; 
		}
		if(s+s2>2*s1)
		{
			x++;
		}
	}
	cout<<x;
	return 0;
}

