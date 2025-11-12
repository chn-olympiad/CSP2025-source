#include<bits/stdc++.h>
using namespace std;
int a[1000011];
int xsqz(int x,int y)
{
	int e=x/y;
	if(x%y!=0)
	{
		return e+1;
	}
	else  
	{
		return e;
	}
 } 
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,sum=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n*m;i++)
	{
		if(a[i]>a[0])
		{
			sum++;
		}
	}
	if(sum<=n)
	{
		cout<<1<<" "<<sum;
	}
	else if(xsqz(sum,n)%2!=0)
	{
		if(sum%n==0)
			cout<<xsqz(sum,n)<<" "<<n;
		else
			cout<<xsqz(sum,n)<<" "<<sum%n;
	}                
	else if(xsqz(sum,n)%2==0)
	{
		if(sum%n==0)
		{
			cout<<xsqz(sum,n)<<" "<<1;
		}
		else
		{
			cout<<xsqz(sum,n)<<" "<<m%(sum-n)+2;
		}
	}
	return 0;
}