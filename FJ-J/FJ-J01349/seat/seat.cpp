#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0; 
int a[105111];
int js=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			js++;
			cin>>a[js];
			a[js]*=-1;
		}
	}
	ans=a[1];
	sort(a+1,a+js+114);
	js=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)// shu zhe xia lai
		{
			for(int j=1;j<=n;j++)
			{
				js++;
				if(a[js]==ans)
				{
					cout<<i<<' '<<j;
					
					cout<<js<<"\n"; 
					return 0;
				}
			}
			
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				js++;
				if(a[js]==ans)
				{
					cout<<i<<' '<<j;
					cout<<js<<"\n"; 
					return 0;
				}
			}
		}
	}
	return 0;	
} 
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
