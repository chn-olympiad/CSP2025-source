#include<bits/stdc++.h>
using namespace std;
int n,m,s,t,d;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			s++;
			cin>>a[s];
			if(s==1)
			{
				t=a[s];
			}
		}
	}	
	d=s;
	sort(a+1,a+s+1);
	s=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			s++;
			if(a[d-s+1]==t)
			{
				if(i%2==1)
				{
					cout<<i<<" "<<j;
					exit(0);
				}
				else
				{
					cout<<i<<" "<<m-j+1;
					exit(0);
				}
			}
		}
	}	
}
