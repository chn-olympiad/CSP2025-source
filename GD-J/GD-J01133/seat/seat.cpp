#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[15][15],b,c,d,x[150]={0},r,sum=0;
	cin>>b>>c;
	d=b*c;
	for(int i=1;d>=i;i++)
	{
		int e;
		cin>>e;
		if(i==1)
		{
			r=e;
		}
		x[e]++;
	}
	for(int i=100;r<=i;i--)
	{
		if(x[i]>0)
		{
			sum++;
		}
	}
	int j,k;
	j=sum%b;
	k=(sum-1)/b+1;
	if(k%2==1)
	{
		if(j==0)
		{
			j=b;
		}
		cout<<k<<" "<<j;
	}
	else
	{
		cout<<k<<" "<<c-j+1;
	}
	return 0;
}
