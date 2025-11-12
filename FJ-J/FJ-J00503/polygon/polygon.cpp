#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int t=3,k=0;
	while  (t<=n)
	{
		if (t==3)
		{
			if (a[1]+a[2]>a[3])
			{
				k+=1;
			}
		}
		
	}
	cout<<k;
}
