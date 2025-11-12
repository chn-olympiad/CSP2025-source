#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[110]; 
int R,S;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+m*n+1);
	
	for(int i=1;i<=n*m;i++)
	if(a[i]==R) S=n*m-i+1;

	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				S--;
				if(S==0)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				S--;
				if(S==0)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	
	return 0;
}
