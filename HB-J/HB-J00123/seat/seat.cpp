#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,r=1;
	int s[105];
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<m*n;i++)
	{
		for(int j=i+1;j<=m*n;j++)
		{
			if(s[i]<s[j])
			{
				swap(s[i],s[j]);
				if(i==r)
				{
					r=j;
				}
			}
		}
	}
	if(r%n==0)
	{
		if((r/n)%2==0)
		{
			cout<<r/n<<" "<<"0";
		}
		else
		{
			cout<<r/n<<" "<<n;
		}
	}
	else
	{
		if((r/n)%2==0)
		{
			cout<<r/n+1<<" "<<r%n;
		}
		else
		{
			cout<<r/n+1<<" "<<n-r%n+1;
		}
	}
	return 0;
}
