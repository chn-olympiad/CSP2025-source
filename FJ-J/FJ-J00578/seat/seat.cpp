#include<bits/stdc++.h>
using namespace std;
int n,m,s[102],cnt,a;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	a=s[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(s[j]>s[i])
			{
				swap(s[j],s[i]);
			}
		}
		
	}	
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				cnt++;
				if(s[cnt]==a)
				{
					cout<<i<<" "<<j;
					return 0;
				}		
			}
		}
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				cnt++;
				if(s[cnt]==a)
				{
					cout<<i<<" "<<j;
					return 0;
				}		
			}
		}
	}	
	return 0;
}
