#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	if (n<=3)
	{
		if((a[0]+a[1]>a[2])&&(a[0]+a[2]>a[1])&&(a[2]+a[1]>a[0]))
		{
			cout<<"1";
		}
		else cout<<"0";
	}
	return 0;
}
