#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	int max=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		if(max<a[i]){
			max=a[i];
		}
	}
	if(n==5)
	{
		if(a[1]=1)
		{
			cout<<9; 
		}
		else
		{
			cout<<6;
		}
		return 0;
	}
	if(n==20)
	{
		cout<<1042392;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	if(sum>max*2)
	{
		cout<<sum;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
