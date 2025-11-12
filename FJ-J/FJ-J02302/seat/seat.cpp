#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a0,n1,m1;
	cin>>n>>m;
	int nm = n*m;
	int a[100];
	for(int i = 0;i<nm;i++)
	{
		cin>>a[i];
	}
	a0 = a[0];
	int num;
	for(int i = 0;i<nm;i++)
	{
		for(int j = 0;j<nm-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				num = a[j];
				a[j] = a[j+1];
				a[j+1] = num;
			}
		}
	}
	for(int i =0;i<nm;i++)
	{
		if(a[i] == a0)
		{
			if(((i+1)/n%2 == 0||(i+1)%n == 0)&&(i+1)%(2*n)!=0)
			{
				if((i+1)%n == 0)
				{
					m1 = (i+1)/n;
					n1 = n;
				}
				else
				{
					m1 = (i+1)/n+1;
					n1 = (i+1)%n;
				}
			}
			else
			{
				if((i+1)%n == 0)
				{
					m1 = (i+1)/n;
					n1 = 1;
				}
				else
				{
					m1 = (i+1)/n+1;
					n1 = n-((i+1)%n)+1;
				}
			}
		}
	}
	cout<<m1<<" "<<n1;
	return 0;
}