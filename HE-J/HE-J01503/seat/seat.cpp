#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.cpp","r",stdin);
	freopen("seat.cpp","w",stdout);
	int a[101],n,m,c[101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>c[i];		
	}
	int r=c[1],nm=n*m;
	sort(c+1,c+nm+1);
	int j=1;
	for(int i=nm;i>=1;i--)
	{
		a[j]=c[i];
		j++;	
	}
	int l,h;
	for(int i=1;i<=nm;i++)
	{
		if(r==a[i])
		{
			if(i<=n)
			{
				cout<<1<<" "<<i;
				return 0;				
			}
			else
			{
				if(i%n==0)
				{
					if((i/n)%2==0)
					{
						h=0;
						l=i/n;
					}
					else
					{
						l=i/n+1;
						h=n;
					}
				}
				else if((i-1)%n==0)
				{
					if(i/n%2==0)
					{
						l=i/n+1;
						h=1;
					}
					else
					{
						l=i/n+1;
						h=n;
					}
				}
				else
				{
					if((i/n+1)%2==0)
					{
						h=n-(i/n);
						l=i/n+1;
					}
					else
					{
						l=i/n+1;
						h=i/n;
					}
				}
			}
			break;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
