#include<bits/stdc++.h>
using namespace std;
int a[20][20],n,m,t,b[1010],s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>b[i];
	s=b[1];
	sort(b+1,b+1+n*m);
	for(int i=n*m;i>=1;i--)
		if(s==b[i])
		{
			s=n*m-i+1;
			break;
		}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
			for(int j=1;j<=n;j++)
			{
				a[j][i]=++t;
				if(s==t)
				{
					cout<<i<<" "<<j;
					break;
				}
			}
		else
			for(int j=n;j>=1;j--)
			{
				a[j][i]=++t;
				if(s==t)
				{
					cout<<i<<" "<<j;
					break;
				}
			}	
	}
	return 0;			
}
