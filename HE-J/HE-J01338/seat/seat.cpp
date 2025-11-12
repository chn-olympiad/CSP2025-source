#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin >>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cin >>a[i*j];
			int s=a[0];
			if(a[i*j]<a[i*(j+1)])
			{
				a[i*j]=a[i*(j+2)];
				a[i*(j+1)]=a[i*j];
				a[i*(j+2)]=a[i*j];
				if(i%2==1)
				{
					j=m;
					j--;
				}
				else
				{
					j=0;
					j++;
				}
				if(s==a[i*j])
				{
					cout<<i<<j;
				}
			}
		}
	}
	return 0;
}
