#include<bits/stdc++.h>
using namespace std;
long long int a[101010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long int c,r;
	cin>>c>>r;
	for(long long int i=1;i<=c*r;i++)
	{
		cin>>a[i];
	} 
	long long int Rs=a[1],sum=0;
	for(long long int i=2;i<=c*r;i++)
	{
		if(a[i]>Rs)
		{
			sum++;
		}
	}
	long long int line=(sum+1)/c+((sum+1)%c==0?0:1);
	cout<<line<<" ";
	if(line%2==1)
	{
		long long int row=(sum+1)%c;
		if(row==0)
		{
			cout<<c;
		}
		else
		{
			cout<<row;
		}
	}
	else
	{
		long long int row=(sum+1)%c;
		if(row==0)
		{
			cout<<1;
		}
		else
		{
			cout<<c-row+1;
		}
	}
}
