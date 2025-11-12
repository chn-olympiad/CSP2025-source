#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	int a[n];
	int max=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		if(max<a[i])
		{
			max=a[i];
		}
	}
	max*=2;
	if(n==3&&sum>max)
	{
		cout<<1;
	}
	 return 0;
}
 
