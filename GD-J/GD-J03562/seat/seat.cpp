#include<bits/stdc++.h> 
using namespace std;
int a[100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,lie,hang,sum=1;
	cin>>n>>m;
	for(int i=0;i<m*n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n*m;i++)
	{
		if(a[i]>a[0])
		{
			sum+=1;
		}
	}
	if(sum%n==0)
	{
		lie=sum/n;
		{
			if(lie%2==0)
			{
				hang=1;
			}
			else
			{
				hang=n;
			}
		}
	}
	else
	{
		lie=sum/n+1;
		if(lie%2!=0)
		{
			hang=sum%n;
		}
		else
		{
			int manbo=sum%n;
			hang=n-manbo+1;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
