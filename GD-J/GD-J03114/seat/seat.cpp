#include<bits/stdc++.h>
using namespace std;

int n,m,ax,a1,pm=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	for(int i=1;i<n*m;i++)
	{
		cin>>ax;
		if(ax>a1) pm++;
	}
	for(int i=1;i<=m;i++)
	{
		if(i*n>=pm)
		{
			cout<<i<<' ';
			if(i%2==0)
			{
				cout<<n*i-pm+1;
			}
			else
			{
				cout<<pm-(i-1)*n;
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
